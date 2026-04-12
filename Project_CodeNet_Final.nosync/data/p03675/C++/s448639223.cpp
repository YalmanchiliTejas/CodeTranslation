#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1

int n;

int main(){
    cin >> n;
    vector<ll> ans(n);
    rep(i,n){
        ll num;
        ll idx = n/2;
        if(n % 2 == 0){
            if(i%2 == 0)idx += i/2;
            else idx -= (i+1)/2;
        }
        else {
            if(i%2 == 0)idx -= i/2;
            else idx += (i+1)/2;
        }
        // cout << "!" << " " << idx << endl;;
        cin >> num;
        ans[idx] = num;
    }
    rep(i,n){
        if(i != n-1)cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }
}