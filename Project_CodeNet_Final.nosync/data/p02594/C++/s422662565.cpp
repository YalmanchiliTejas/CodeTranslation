#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forr(i,n) for(ll i=0;i<n;i++)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define vi vector<ll>
#define endl '\n'
#define ce(ele) cout<<ele<<' '
#define cs(ele) cout<<ele<<'\n'
#define CASE(t) ll t; cin>>t; while(t--)
#define sor(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())

ll power(ll a,ll b){ll r=1;while(b--)r*=a;return r;}

int solve(int a,int b){
    if(a==b)return 0;
    return 1+solve(min(a,b),max(a,b)-min(a,b));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;cin>>n;
    if(n>=30)cs("Yes");
    else cs("No");
    

  }
