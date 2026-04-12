#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//#define f(i,a,n) for(ll i=a;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() 
{
    fast;
    string s;
    cin>>s;
    //cout<<s;
    for(ll i=0;i<2;i++)
    {
        //cout<<s[i];
        if(s[i]!=s[i+1])
        {
            cout<<"Yes";
            exit(0);
        }
    }
    cout<<"No";
    return 0;
}