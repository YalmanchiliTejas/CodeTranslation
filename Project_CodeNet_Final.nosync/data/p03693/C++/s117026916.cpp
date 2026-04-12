#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define mll map<ll,ll>
#define sll set<ll>
#define fo(i,n) for(i=0;i<n;i++)
#define MOD 1000000007
using namespace std;

int main()
{
    ios::sync_with_stdio(false);


    ll n,i,j,k,t;
    cin>>i>>j>>k;

    if((i*100+j*10+k)%4==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
