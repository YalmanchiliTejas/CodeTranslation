#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin>>N;
    vector<ll> A;
    rep(i,0,N){
        ll a;
        cin>>a;
        A.pb(a);
    }
    sor(A);
    ll res1=0,res2=0;
    if(N%2){
        rep(i,N/2+1,N){
            res1+=2*A[i];
        }
        rep(i,0,N/2-1){
            res1-=2*A[i];
        }
        res1-=A[N/2-1]+A[N/2];
        rep(i,0,N/2){
            res2-=2*A[i];
        }
        rep(i,N/2,N){
            res2+=2*A[i];
        }
        res2-=A[N/2]+A[N/2+1];
    }
    else{
        rep(i,N/2,N){
            res1+=2*A[i];
        }
        rep(i,0,N/2){
            res1-=2*A[i];
        }
        res1+=-A[N/2]+A[N/2-1];
    }
    cout <<max(res1,res2)<<"\n";
}