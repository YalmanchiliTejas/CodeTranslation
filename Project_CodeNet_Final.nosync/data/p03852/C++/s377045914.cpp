#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int g=getchar();
    if(g=='a'||g=='e'||g=='i'||g=='o'||g=='u')
        cout<<"vowel";
    else
        cout<<"consonant";
    return 0;
}