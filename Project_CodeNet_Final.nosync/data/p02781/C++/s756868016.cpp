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
#define GOODBYE do { cout << "NO" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    string N;
    int K;
    cin >> N >> K;
    
    int dp[104][11][5]={};
    REP(j,10){
        if(j==0){
            dp[0][j][0]=1;
        }else{
            dp[0][j][1]=1;
        }
    }
    
    REP(k,K+1){
        REP(i,N.size()){
            if(i==0)continue;
            REP(j,10){
                if(j==0){
                    REP(l,10){
                        dp[i][j][k]+=dp[i-1][l][k];
                    }
                }else if(k!=0){
                    REP(l,10){
                        dp[i][j][k]+=dp[i-1][l][k-1];
                    }
                }
            }
        }
    }
    
    /*REP(k,K+1){
        REP(i,N.size()){
            REP(j,10){
                cout << dp[i][j][k] << " ";
            }cout << endl;
        }cout << endl;
    }*/
    
    int Ans=0;
    int k=K;
    RREP(i,N.size()){
        int D=N[N.size()-1-i]-'0';
        if(i==0)D++;
        REP(j,D){
            Ans+=dp[i][j][k];
        }
        //cout << D MM Ans << endl;
        if(D!=0)k--;
        if(k<0)break;
    }
    cout << Ans << endl;
    
    return 0;
}

