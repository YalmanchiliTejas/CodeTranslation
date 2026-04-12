#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef pair<int , int> i_i;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<ll>> ve_vel;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<bool>> ve_veb;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define repk(i,k,n) for(int i=k;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) *max_element(all(a))
#define minel(a) *min_element(all(a))
#define acc accumulate
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    int N; cin >> N;
    vel A(N); rep(i,N) cin >> A[i];

    if(N % 2 == 0) {
        ll ans1 = 0LL;
        sort(rall(A));
        rep(i,N/2) {
            if(i == N/2 - 1) ans1 += A[i];
            else ans1 += 2 * A[i];
        }
        sort(all(A));
        rep(i,N/2) {
            if(i == N/2 - 1) ans1 -= A[i]; 
            else ans1 -= 2 * A[i];
        }
        cout << ans1 << endl;
        return 0;
    }
    else {
        ll ans1 = 0LL;
        sort(rall(A));
        rep(i,N/2) ans1 += 2 * A[i];
        sort(all(A));
        rep(i,(N+1)/2) {
            if(i == (N+1)/2 -1 or i == (N+1)/2 - 2 ) ans1 -= A[i]; 
            else ans1 -= 2 * A[i];
        }

        ll ans2 = 0LL;
        sort(rall(A));
        rep(i,(N+1)/2) {
            if(i == (N+1)/2 - 1 or i == (N+1)/2 - 2) ans2 += A[i];
            else ans2 += 2 * A[i]; 
        }
        sort(all(A));
        rep(i,N/2) {
            ans2 -= 2 * A[i];
        }
        cout << max(ans1, ans2) << endl;
        return 0;
    }
}
