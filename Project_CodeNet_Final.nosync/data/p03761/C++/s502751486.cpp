#include <bits/stdc++.h>
#define ll long long
#define REV(v) reverse(v.begin(), v.end());
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, start, stop) for (ll i = start; i < stop; i++)
#define FORR(i, start, stop) for (ll i = start; i > stop; i--)
#define SORT(v, n) sort(v, v + n);
#define SORTR(v, n) sort(v, v + n,greater<ll>());
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.begin(), v.end(),greater<ll>());
#define REMOVE(v,n) remove(vector<ll> v,v+v.size(),ll n)
#define ERASE(v,n) v.erase(v.begin()+n);
#define ull unsigned long long
#define pb(a) push_back(a)
#define INF 999999999
#define V(v,i,j) vector(v.begin() + i, v.begin() + j)
#define INSERT(va,vb) va.insert(va.end(), vb.begin(), vb.end())
using namespace std;
typedef vector<ll> vll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
const int MOD = 1000000007;
void chmin(int &a, int b) { if (a > b) a = b; }
//string al="abcdefghijklmnopqrstuvwxyz";
//vector< vector<int> > v (size1, vector<int>(size2) );



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string al="abcdefghijklmnopqrstuvwxyz";
    ll N;
    cin>>N;
    vector< vector<ll> > cnt (N, vector<ll>(26,0) );
    string S;
    FOR(i,0,N){
        cin>>S;
        FOR(j,0,S.size()){
            cnt[i][S[j]-'a']++;
        }
    }

    
    FOR(i,0,26){
        ll a=10e9;
        FOR(j,0,N){
            a=min(cnt[j][i],a);
        }
        FOR(k,0,a){
            cout<<al[i];
        }
    }
}