#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PPQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> &vec){ return (ll)vec.size(); }
ll sz(string &s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }

bool check(ll k,string &s,string &ans){
    bool flag;
    if(ans[k] == 'S'){
        if(s[k] == 'o'){
            flag = (ans[k-1] == ans[k+1]);
        }
        else{
            flag = (ans[k-1] != ans[k+1]);
        }
    }
    else{
        if(s[k] == 'x'){
            flag = (ans[k-1] == ans[k+1]);
        }
        else{
            flag = (ans[k-1] != ans[k+1]);
        }
    }

    return flag;
}

bool func(ll &n, string &s, string &ans){
    rep(i,3,sz(s)){
        if(ans[i-1] == 'S'){
            if(s[i-1] == 'o') ans[i] = ans[i-2];
            else ans[i] = (ans[i-2] == 'S'?'W':'S');
        }
        else{
            if(s[i-1] == 'o') ans[i] = ((ans[i-2] == 'S')?'W':'S');
            else ans[i] = ans[i-2];
        }
    }


    string tmp1 = s[n-1] + s + s[0];
    string tmp2 = ans[n-1] + ans + ans[0]; 
    return (check(1,tmp1,tmp2) && check(n,tmp1,tmp2));
}

int main(){
    ll n;
    string s;
    cin >> n >> s;
    
    string ans(sz(s),' ');
    rep(i,0,8){
        rep(j,0,3){
            ans[j] = (((i >> j) & 1)?'S':'W');
        }
        if(s[1] == 'o'){
            if(ans[1] == 'W' && ans[0] == ans[2]) continue;
            if(ans[1] == 'S' && ans[0] != ans[2]) continue;
        }
        else{
            if(ans[1] == 'S' && ans[0] == ans[2]) continue;
            if(ans[1] == 'W' && ans[0] != ans[2]) continue;
        }
        if(func(n,s,ans)){
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
