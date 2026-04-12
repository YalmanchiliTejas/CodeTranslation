#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        bool temp=true;
        for(int j=0;j<i;j++)
        {
            if(h[j]>h[i])
            {
                temp=false;
                break;
            }
        }
        if(temp)
        {
            ans++;
        }
    }
    cout<<ans;
}