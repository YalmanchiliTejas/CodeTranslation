#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

int main()
{
ll n;
cin >> n;
string s;
cin >> s;
ll k;
cin >> k;
char a=s[k-1];
rep(i,n){
    if(a!=s[i])s[i]='*';
}


cout << s << endl;
return 0;
}






