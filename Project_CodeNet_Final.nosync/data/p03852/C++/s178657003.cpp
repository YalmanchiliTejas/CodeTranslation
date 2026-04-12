#include <stdio.h>
                                                                                                
  
int main(void){
                                                                                                
   
    int i;

    char c;
   
    char s[6] = {"aiueo"};
   
      
    scanf("%c", &c);
   
    
    for( i = 0 ; i < 5 ; i = i + 1 ){

         if( s[i] == c ){

             printf("vowel\n");

             return 0;

             }

         }

    printf("consonant\n");


    return 0;
                                                          
}