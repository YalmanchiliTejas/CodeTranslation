#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
//const long long MOD = ;
const long long INF_LL = 1e18+3; const int INF_int = 1e9+3;
#define ll long long
#define rep(i,n) for(int i = 0;i<n;i++)
#define lrep(i,n) for(long long i = 0;i<n;i++)
#define All(a) a.begin(),a.end()
#define Debug_Output_ALL(a) for(auto itr = a.begin();itr!=a.end();itr++) cout << *itr << " ";cout << endl;
//@brief nCk (O(k))
template <typename T>
T combi_simple(T n,T k,long long MOD = MOD){
    k = min(n-k,k);
    T ret = 1;
    for(T i = n;i>n-k;i--) ret*=i;
    for(T i=1;i<=k;i++) ret/=i;
    return ret;
}
int main(){
    string s;ll k;
    cin >> s >> k;
    ll ans = 0;
    ll n = s.size();
    auto f = [](string s,int k){int t = 0;rep(i,s.size()) if(s[i]!='0') t++;if(t>=k) return true;else return false;};
    if(f(s,k)) ans++;
    rep(i,n){
        if(k==0) break;
        if((n-i)>=k) ans+=max(0,(s[i]-'0')-1)*pow(9,k-1)*combi_simple(n-1-i,k-1);
        if((n-1-i)>=k && s[i]!='0')ans+=pow(9,k)*combi_simple(n-i-1,k);
        if(s[i]!='0') k--;
    }
    cout << ans << endl;
}
