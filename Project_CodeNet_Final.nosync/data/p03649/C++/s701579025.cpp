#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
typedef pair<int,int> PP;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE cout << -1 << endl;return 0
#define MM <<" "<<
#define Endl endl
 
signed main(void){
    int N;
    int A[57];
    cin >> N;
    REP(i,N){
        cin >> A[i];
    }
    int Ans=0;
    while(1){
        bool ch=true;
        REP(i,N){
            if(A[i]>=N){
                ch=false;
            }
        }
        if(ch==true){
            break;
        }
        REP(i,N){
            if(A[i]>=N){
                int E=A[i]/N;
                A[i]-=E*N;
                REP(j,N){
                    if(i==j)continue;
                    A[j]+=E;
                }
                Ans+=E;
            }
        }
    }
    cout << Ans << endl;
 
    return 0;
}

