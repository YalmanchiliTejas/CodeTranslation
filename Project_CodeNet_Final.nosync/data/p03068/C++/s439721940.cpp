#include<bits/stdc++.h>
using namespace std;
int main()

{

    char a[1000];
    int n,k;
    cin>>n>>a>>k;
    char d=a[k-1];
    for(int i=0;i<n;i++)
    {
        if(a[i]!=d)
            a[i]='*';
    }
    cout<<a;
}

