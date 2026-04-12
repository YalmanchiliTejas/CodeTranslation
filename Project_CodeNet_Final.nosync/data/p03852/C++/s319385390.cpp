#include<bits/stdc++.h>
using namespace std;

#define MAX 500000
typedef unsigned long long int ULL;
typedef long long int LL;
typedef unsigned int UI;
typedef long long i64;

bool isvowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;
    else
        return false;
}

int main()
{
    char c;
    cin>>c;
    if(isvowel(c))
        cout<<"vowel"<<endl;
    else
        cout<<"consonant"<<endl;

    return 0;
}
