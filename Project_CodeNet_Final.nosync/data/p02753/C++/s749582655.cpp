#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld  double
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int> 
#define ppp pair<pii,pii>
#define pb push_back
#define N 200003
#define inf (ll)1e9+11
#define warmup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int mod=1e9+7;

signed main()
{
    warmup
    
    string s;
    cin>>s;
    bool f=0,f1=0;
    f=(s[0]=='A' or s[1]=='A' or s[2]=='A');
    f1=(s[0]=='B' or s[1]=='B' or s[2]=='B');
    cout<<((f&f1) ? "Yes":"No");
    
    return 0;
}
