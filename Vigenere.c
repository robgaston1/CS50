#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>


int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("The program will not work unless you enter just one additional argument: a keyword for the cipher!");
        return 1;
    }
    
    string key = argv[1];
    int n = strlen(key);
    
    int shift_array[n];
    for (int c = 0; c < n; c++)
    {
        if (isupper(key[c]))
        {
           shift_array[c] = key[c] - 65;
        } 
        else if (islower(key[c]))
        {
            shift_array[c] = key[c] - 97;
        } 
        else 
        {
            printf("You must use letters only in your keyword");
            return 1;
        }
    }
    
    string phrase = GetString();
    int s_index = 0;
    
    for (int j = 0, l = strlen(phrase); j < l; j++)
    {
        int encrypted;
        if (isupper(phrase[j]))
        {
            encrypted = ((phrase[j] - 65 + shift_array[s_index % n]) % 26) + 65;
            printf("%c", encrypted);
            s_index++;
        } 
        else if (islower(phrase[j]))
        {
            encrypted = ((phrase[j] - 97 + shift_array[s_index % n]) % 26) + 97;
            printf("%c", encrypted);
            s_index++;
        }
        else
        {
            printf("%c", phrase[j]);
        }
            
        
    }
    printf("\n");
}