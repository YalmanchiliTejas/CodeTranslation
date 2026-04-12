#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)

void solve() 
{
    int n;string s;int k;cin>>n>>s>>k;
    char j=s[k-1];
    REP(i,s.size()){
        if(s[i]!=j)s[i]='*';
    }cout<<s<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}