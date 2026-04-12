#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,h[100],c=0,l=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>h[i];
    l=h[0];
    for(int i=0;i<n;i++)
     {   
         if(l<=h[i])
           { c++;
             l=h[i];
           }
     }
     cout<<c;
    
    return 0;
}