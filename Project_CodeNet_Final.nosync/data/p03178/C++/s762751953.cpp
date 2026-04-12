#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

int main() {
    ll MOD = 1000000007;
    string s;
    cin >> s;
    int k = s.size();
    int d;
    cin >> d;
    ll before[d] = {};
    ll ans[d] = {};
    ll keep[d] = {};

    int x = (int)s[0] - 48;
    //cout << x << endl;

    rep(i,10){
        if(i<x){
            ans[i%d]++;
        }else if(i==x){
            keep[i%d]++;
        }else{
            ;
        }
    }

    srep(i,1,k){
        rep(j,d){
            before[j] = ans[j];
            ans[j] = 0;
        }
        x = (int)s[i] - 48;
        ll next_keep[d] = {};
        rep(j,10){
            if(j<x){
                rep(l,d){
                    ans[(l+j)%d] += before[l] + keep[l];
                    ans[(l+j)%d] %= MOD;
                }
            }else if(j==x){
                rep(l,d){
                    ans[(l+j)%d] += before[l];
                    ans[(l+j)%d] %= MOD;
                }
                rep(l,d){
                    next_keep[(l+j)%d] = keep[l];
                }
            }else{
                rep(l,d){
                    ans[(l+j)%d] += before[l];
                    ans[(l+j)%d] %= MOD;
                }
            }
        }
        rep(j,d){
            keep[j] = next_keep[j];
        }
    }

    ll res = ans[0] + keep[0] + MOD - 1;
    res %= MOD;
    cout << res << endl;
}
 
 
