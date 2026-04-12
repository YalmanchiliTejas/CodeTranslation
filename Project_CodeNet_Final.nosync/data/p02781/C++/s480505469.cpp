#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll DPX[110][5];
ll DPY[110][5];

int main(){
    string S;
    cin >> S;
    ll N = S.size();
    ll K;
    cin >> K;

    DPX[0][0] = 1;
    REP(i,N){
        int s = S[i] - '0';
        REP(j,4){
            REP(k,s){
                if(k == 0){
                    DPY[i+1][j] += DPX[i][j] + DPY[i][j];
                }
                else{
                    DPY[i+1][j+1] += DPX[i][j] + DPY[i][j];
                }
            }
            //s
            if(s == 0){
                DPX[i+1][j] += DPX[i][j];
                DPY[i+1][j] += DPY[i][j];
            }
            else{
                DPX[i+1][j+1] += DPX[i][j];
                DPY[i+1][j+1] += DPY[i][j];
            }
            
            REPi(k, (s+1),10){
                DPY[i+1][j+1] += DPY[i][j];
            }
        }
    }


    ll ans = 0;
    ans += DPX[N][K]; 
    ans += DPY[N][K]; 

    cout << ans << endl;
    return 0;
}
