#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,x;
    cin>>n>>x;
    ll cnt=1;
    int mn=x;
    for(int i=1;i<n;i++)
       {
           cin>>x;
           if(x>=mn)
            {
                mn=x;
                cnt++;
            }
       }
       cout<<cnt<<endl;
    return 0;
}
