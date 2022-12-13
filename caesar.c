#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool is_valid(string s);
int main(int argc, string argv[])
{
    if(argc != 2 || is_valid(argv[1]) )
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]);// the key that tells how the words should be encrypt
    //Here we take the text provided by the user
    string plaintext = get_string("PlainText: ");

    printf("Ciphertext: ");

    for(int i = 0; i < strlen(plaintext); i++)
    {
        char ch = plaintext[i];
        if(islower(ch))
        {
            printf("%c",(((ch - 'a') + k)%26 + 'a'));
        }
        else if(isupper(ch))
        {
            printf("%c",(((ch - 'A') + k)%26 + 'A'));
        }
        else
        {
            printf("%c",ch);
        }
    }
    printf("\n");

    return 0;
}




bool is_valid(string s)
{
    for(int i = 0; i < strlen(s);++i)
    {
        char ch = s[i];// holds each character
        if(!isdigit(ch))//checks if it is not a digit
        {
            return 1;
        }
    }
    return 0;
}