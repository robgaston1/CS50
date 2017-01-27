//Search data for possible jpeg images

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//prototypes
int read(void);

int main(int argc, char *argv[])
{
    int filename = -1;
    char name[8];
    FILE* outptr;
    int bytes_returned;
    
    //ensure correct command line arguments
    if (argc !=2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }
    
    //get filename from cli argument
    char *infile = argv[1];
    
    // open input file 
    FILE *fileptr = fopen(infile, "r");
    if (fileptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    do
    {
        uint8_t buffer[512];    
        bytes_returned = fread(buffer, 1, 512, fileptr);
        
        //check to see if beginning of file            
        if(buffer[0] == 0xff &&
        buffer[1] == 0xd8 &&
        buffer[2] == 0xff &&
        (buffer[3] & 0xf0) == 0xe0)
        {
            //check to see if this is the first file found 
            if(filename == -1)
            {
                filename++;
                sprintf(name, "%03i.jpeg", filename);
                outptr = fopen(name, "w");
                fwrite(buffer, 1, 512, outptr);
            }
            else
            {
                fclose(outptr);
                filename++;
                sprintf(name, "%03i.jpeg", filename);
                outptr = fopen(name, "w");
                fwrite(buffer, 1, 512, outptr);
            }
        }
        else
        {
            if(filename > -1)
            {
                fwrite(buffer, 1, 512, outptr);
            }
        }
    } 
    while(bytes_returned == 512);

    //close open file, end of program
    fclose(outptr);
        
    
        
}

