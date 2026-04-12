#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> i_i;

#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define ALL(v) v.begin(), v.end()
#define SZ(x) ((int)(x).size())

const double PI  = acos(-1.0);
const double EPS = 1e-9;
const ll INF = 1e9+10;
const ll mod = 1e9+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define print(x) cerr << #x << " is " << x << endl;
//#define print(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl; 

ll dp0[200][5], dp1[200][5];


int A[200];

int main() {
    string S;
    cin >> S;
    int L = S.size(), K;
    cin >> K;
    rep(i, L){
        A[i] = S[i] - '0';
        //cout << A[i];
    }
    //cout << endl;
    
    dp0[0][1] = A[0] - 1;
    dp0[0][0] = 1;
    dp1[0][1] = 1;
    reps(i, 1, L){
        //cout << "A[i] = " << A[i] << endl; 
        rep(j, 4){
            dp0[i][j + 1] += dp0[i - 1][j] * 9;
            dp0[i][j] += dp0[i - 1][j];
            
            if (A[i] == 0){
                dp1[i][j] = dp1[i - 1][j];
            } else {
                dp1[i][j + 1] = dp1[i - 1][j];
                dp0[i][j + 1] += dp1[i - 1][j] * (A[i] - 1);
                dp0[i][j] += dp1[i - 1][j];
            }
        }
    }
    cout << dp0[L - 1][K] + dp1[L - 1][K];
    return 0;
}
