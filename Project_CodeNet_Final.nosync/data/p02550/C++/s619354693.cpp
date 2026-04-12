#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using P = pair<int,int>;

template <class _T> inline bool chmax (_T& a,_T b){if(a<b){a=b;return true;}return false;}
template <class _T> inline bool chmin (_T& a,_T b){if(a>b){a=b;return true;}return false;}
const int inf = 2147483647;
const long long INF = 1LL << 60;
const int MAX_N = 11000;
const int MAX_W = 10100;
ll mod = 1000000007;
ll MOD = 998244353;

int main(void){
    ll n;cin >> n;
    ll x,m;cin >> x >> m;
    vector<ll> v;
    ll sum = 0;
    vector<bool> table(m+1,false);

    for(int i=0;i<n;i++){
        
        if(x==0){ 
            cout << sum << endl;
            return 0;
        }
        if(table[x]){
            ll pos,tmp_sum=0;
            for(int j=0;j<v.size();j++){
                if(v[j]==x){
                    pos = j;
                    break;
                } 
                tmp_sum += v[j];
            }
            sum = (sum-tmp_sum)*((n-pos)/(v.size()-pos));
            sum += tmp_sum;
            for(ll j=0;j<(n-pos)%(v.size()-pos);j++){
                sum += v[pos+j];
            }
            break;
        }
        sum += x;
        v.push_back(x);
        table[x] = true;
        x = x*x;
        x %= m;
    }
      cout << sum << endl;
    return 0;
}