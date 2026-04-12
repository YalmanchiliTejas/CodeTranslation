#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ll long long
#define ull unsigned long long
#define ld long double
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rrep(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define pll pair<long long,long long>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define vvc vector<vector<char>>
#define vc vector<char>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define maxe(x) *max_element(all(x))
#define mine(x) *min_element(all(x))
#define Size(x) ((int)(x).size())
#define umap unordered_map
const long long INF = 1LL << 60;
const long double pi = 3.1415926535897932;
long long MOD = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

    template<class T> inline bool chmin(T& a, T b) {
        if (a > b) {
            a = b;
            return true;
        }
        return false;
    }
    template<class T> inline bool chmax(T& a, T b) {
        if (a < b) {
            a = b;
            return true;
        }
        return false;
    }

//lis,modpow,uf,modncr,soinsubunkai,yakusurekkyo,gyakugen
//mint

    signed main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ll N;
        cin>>N;
        vl X(N);
        vl C(N);
        rep(i,N){
            cin>>X[i];
            C[i]=X[i];
        }
        sort(all(C));
        ll r=C[N/2];
        ll l=C[N/2-1];
        rep(i,N){
            if(X[i]<=l){
                cout<<r<<endl;
            }else{
                cout<<l<<endl;
            }
        }
    }