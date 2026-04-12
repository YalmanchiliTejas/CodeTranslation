#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
//#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl
#define debug false

signed main(void){
    int N,a;
    vector<int> A;
    cin >> N;
    REP(i,N){
        cin >> a;
        A.push_back(a);
    }
    
    int dp[4][214514]={};
    REP(j,4){
        REP(i,N+3){
            dp[j][i]=-INF;
        }
    }
    dp[0][0]=0;
    REP(j,3){
        REP(i,N){
            dp[j][i+2]=max(dp[j][i+2],dp[j][i]+A[i]);
            dp[j+1][i+1]=max(dp[j+1][i+1],dp[j][i]);
        }
    }
    
    int Ans=-INF;
    
    #if debug
    REP(j,3){
        REP(i,N+3){
            if(dp[j][i]<-INF/10){
                cout << "-∞ ";
            }else{
                cout << dp[j][i] << " ";
            }
        }cout << endl;
    }
    #endif
    
    REP(i,3){
        if(N%2==0){
            Ans=max(Ans,dp[i][N+i]);
        }else{
            Ans=max(Ans,dp[i][N-1+i]);
        }
    }
    
    cout << Ans << endl;
    return 0;
}

