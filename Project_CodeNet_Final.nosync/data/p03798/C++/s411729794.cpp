#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
constexpr int MOD = 1000000007;
constexpr int INF = numeric_limits<int>::max() / 2;
typedef pair<int,int> P;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const double PI = acos(-1.0);
// cout << fixed << setprecision(14);
 
signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

    int N;
    string S;
    cin >> N >> S;
    int A[N]{};
    rep(i,2){
        rep(j,2){
            rep(i,N) A[i] = 0;
            bool ok1{}, ok2{};
            A[0] = i;
            A[1] = j;
            for(int i=2;i<N;i++){
                if(A[i-1] == 0){
                    if(S[i-1] == 'o'){
                        A[i] = A[i-2];
                    }
                    else{
                        A[i] = (A[i-2] ^ 1);
                    }
                }
                else{
                    if(S[i-1] == 'o'){
                        A[i] = (A[i-2] ^ 1);
                    }
                    else{
                        A[i] = A[i-2];
                    }
                }
            }

            if(A[N-1] == 0){
                if(S[N-1] == 'o'){
                    if(A[N-2] == A[0]) ok1 = true;
                }
                else{
                    if(A[N-2] == (A[0] ^ 1)) ok1 = true;
                }
            }
            else{
                if(S[N-1] == 'o'){
                    if(A[N-2] == (A[0] ^ 1)) ok1 = true;
                }
                else{
                    if(A[N-2] == A[0]) ok1 = true;
                }
            }
            if(A[0] == 0){
                if(S[0] == 'o'){
                    if(A[N-1] == A[1]) ok2 = true;
                }
                else{
                    if(A[N-1] == (A[1] ^ 1)) ok2 = true;
                }
            }
            else{
                if(S[0] == 'o'){
                    if(A[N-1] == (A[1] ^ 1)) ok2 = true;
                }
                else{
                    if(A[N-1] == A[1]) ok2 = true;
                }
            }
            if(ok1 && ok2){
                rep(i,N){
                    if(A[i]){
                        cout << "W";
                    }
                    else{
                        cout << "S";
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}