#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE cout << "NO" << endl;return 0
#define MM <<" "<<
#define Endl endl


signed main(void){
    int N;
    int s[114514];
    cin >> N;
    REP(i,N){
        cin >> s[i];
    }
    int Ans=0;
    for(int C=1;C<=N-1;C++){
        int sum=0;
        for(int k=1;k<((N-1)%C==0?((N-1)/C+1)/2:(N-1)/C);k++){
            sum+=s[k*C]+s[N-1-k*C];
            Ans=max(Ans,sum);
            //cout << C MM k MM sum<< endl;
        }
    }
    cout << Ans << endl;
    return 0;
}
