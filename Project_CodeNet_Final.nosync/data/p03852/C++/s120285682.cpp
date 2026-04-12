#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define sc scanf
using namespace std;
char c;
int main(){
    c=getchar();
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')cout<<"vowel\n";
    else cout<<"consonant\n";
    return 0;
} 