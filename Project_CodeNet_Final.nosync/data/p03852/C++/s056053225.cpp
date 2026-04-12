#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    char ch;

    scanf("%c",&ch);

    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        printf("vowel\n");

    else
        printf("consonant\n");


    return (0);
}
