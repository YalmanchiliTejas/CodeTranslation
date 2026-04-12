#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
 char ch;
 scanf("%c",&ch);
 ch=tolower(ch);
 if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    printf("vowel\n");
 else
    printf("consonant\n");

}
