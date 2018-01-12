#include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 #include <ctype.h>

 int main(int argc, string argv[])
 {
     int j=0;
     bool keySuccessful = false;
     int input_length = 0;
     string txt = "";
     int max=0;
     do
     {
         if(argc != 2)
         {
             printf("You didn't submit a valid encryption key.\n");
             printf("Please check your input and re-run the programm.\n");
             printf("We require only string as encryption key.\n");
             return 1;
         }
         else
         {
             max = strlen(argv[1]);
             keySuccessful = true;
         }
     } while(!keySuccessful);
      for(int i = 0; i < max; i++)
     {

         if(isalpha(argv[1][i]))
         {

             if(islower(argv[1][i]))
             {
                 argv[1][i]=argv[1][i]-32;
             }
             else
             {

             }

         }
         else
         {
             return 1;
         }
     }
     printf("plaintext: ");
     txt = get_string();
     input_length = strlen(txt);
     printf("ciphertext: ");

     for(int i = 0; i < input_length; i++)
     {

         if(isalpha(txt[i]))
         {

             if(islower(txt[i]))
             {
                 printf("%c", (((txt[i] -97+argv[1][j]-65)%26)+97));
             }
             else
             {
                 printf("%c", (((txt[i] - 65+argv[1][j]-65)%26)+65));
             }
             j++;
             if(j==max)
             {j=0;}
         }
         else
         {
             printf("%c", txt[i]);
         }
     }
     printf("\n");
     return 0;
 }
