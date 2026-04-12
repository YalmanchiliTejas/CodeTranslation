#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=(ll)a;i<(ll)b;i++)
#define revrep(i,a,b) for(i=(ll)a;i>=(ll)b;i--)
#define ii pair<double,double>
#define pb push_back
#define f first
#define s second
#define ll long long int
#define vi vector<ll>
#define rs resize
int main()
{
     std::ios::sync_with_stdio(false);
     ll a,b,c;
     cin>>a>>b>>c;
     a = 100*a + 10*b+c;
     if(a%4==0)
      cout<<"YES";
     else
      cout<<"NO";
     return 0;
}
