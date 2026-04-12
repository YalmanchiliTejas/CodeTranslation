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

string N;
int K;

int dp[114][2][10];

int keta(int k,bool f,int m){
    if(dp[k][f][m]!=-1){
        return dp[k][f][m];
    }
    if(m<0)return 0;
    if(k>=N.size()){
        int num = (!m?1:0);
        dp[k][f][m]=num;
        return num;
    }
    
    if(f){
        int num=0;
        REP(i,10){
            num+=keta(k+1,1,(i?m-1:m));
        }
        dp[k][f][m]=num;
        return num;
    }else{
        int num=0;
        int s = N[k]-'0';
        REP(i,s){
            num+=keta(k+1,1,(i?m-1:m));
        }
        num+=keta(k+1,0,(s?m-1:m));
        dp[k][f][m]=num;
        return num;
        
    }
    
}


signed main(void){
    cin >> N;
    cin >> K;
    
    REP(i,114){REP(j,2){REP(k,10){dp[i][j][k]=-1;}}}
    
    int Ans = keta(0,0,K);
    cout << Ans << endl;
    
    return 0;
}


