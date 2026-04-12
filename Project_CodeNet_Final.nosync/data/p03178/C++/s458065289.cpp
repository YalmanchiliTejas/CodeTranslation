#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
typedef long long ll;
typedef pair<ll,ll> PP;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl
#define debug false
#define debug2 false

string S;
int D;

int dp[14514][2][104];

int keta(int k,bool f,int m){
    if(dp[k][f][m]!=-1){
        return dp[k][f][m];
    }
    if(k>=S.size()){
        int num=0;
        if(m==0)num=1;
        dp[k][f][m]=num;
        return num;
    }
    
    if(f==0){
        int num=0;
        REP(i,10){
            num+=keta(k+1,0,(m+i)%D);
        }
        num%=MOD;
        dp[k][f][m]=num;
        return num;
    }else{
        int num=0;
        int s = S[k]-'0';
        REP(i,s){
            num+=keta(k+1,0,(m+i)%D);
        }
        num+=keta(k+1,1,(m+s)%D);
        dp[k][f][m]=num;
        return num;
    }
    
}

signed main(void){
    cin >> S;
    cin >> D;
    
    REP(i,14514){
        REP(j,2){
            REP(k,104){
                dp[i][j][k]=-1;
            }
        }
    }
    
    int Ans = keta(0,1,0);
    Ans+=(MOD-1);
    Ans%=MOD;
    cout << Ans << endl;
    
    #if debug
    REP(j,D){
        REP(i,S.size()+1){
            cout << dp[i][0][j] << " ";
        }cout << endl;
    }cout << endl;
    
    REP(j,D){
        REP(i,S.size()+1){
            cout << dp[i][1][j] << " ";
        }cout << endl;
    }cout << endl;
    #endif
    
    return 0;
}


