#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;

    fflush(stdin);
    string s;
    cin>>s;

    int k;
    cin>>k;

    for(i=0;i<n;i++)
        if(s[i]!=s[k-1])
            s[i]='*';

    cout<<s;

return 0;
}
