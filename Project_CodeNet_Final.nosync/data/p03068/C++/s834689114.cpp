#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    string a;
    char b;
    cin>>n;
    cin>>a;
    cin>>k;
    b=a[k-1];
    for(int i=0;i<n;i++)
        if(a[i]==b)
        cout<<a[i];
    else
        cout<<"*";
    return 0;
}
