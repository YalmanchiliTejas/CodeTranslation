#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[6];
    scanf("%s",a);
    int n=strlen(a);
    for(int i=0;i<n;i++)
    {
        if(a[i]=='A'&&a[i+1]=='C')
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}