/*
   Creator - Glitched
   Yeet!!
*/
#include "bits/stdc++.h"

using namespace std;

#define testcases ll T;cin>>T;while(T--)
#define ll long long
#define loop(i,x,n) for(ll i=x;i<n;i++)
#define loopr(i,x,n) for(ll i=n-1;i>=x;i--)
#define ff first
#define ss second
#define pb push_back
#define elif else if
#define flush cout<<"\n"
#define mod 1E9+7
#define L LONG_MAX
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const string yes = "Yes", no = "No";
// vector<bad()ool> v(1E5, false);

int main()
{
    string s;
    cin>>s;
    ll a=0,b=0;
    loop(i,0,3){
        if(s[i]=='A')
            a++;
        else
            b++;
    }

    if(a==0 || b==0){
        cout<<"No";
    }
    else
        cout<<"Yes";


}