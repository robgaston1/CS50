#include <stdio.h>
#include <cs50.h>

int collatz(int, int);

int main(void)
{
    int test = GetInt();
    int ans = collatz(test,0);
    printf("%i\n", ans);


}

 int collatz(int n, int s) 
    {
        
        
        printf("%i, %i\n", s, n);
        if (n == 1)
        {
            return s;
        }
        else if (n % 2 == 0)
        {
            s++;
            return collatz(n/2, s);
        }
        else 
        {
            s++;
            return collatz((3 * n) + 1, s);
        }
}
