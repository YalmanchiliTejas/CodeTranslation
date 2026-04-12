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
    //Nは最大で100桁あるので、longlongではオーバーフローしてしまう
    //そこでstringで入力する
    int K;
    cin >> N >> K;
    
    //桁DPの典型的な問題
    //まず、Nの具体的な値は無視して、以下のDPをする
    //dp[i][j][k]=[j*10^i,(j+1)*10^i)までに0でない桁がk桁あるような数の個数
    //このDPは、以下の遷移で求まる
    //dp[i][j][k]=(i=0 j=0 k=0)1
    //            (i=0 j=0 k!=0)0
    //            (i=0 j!=0 k=1)1
    //            (i=0 j!=0 k!=1)0
    //            (i!=0 j=0)Σ[j,0~9] dp[i-1][j][k]
    //            (i!=0 j!=0)Σ[j,0~9] dp[i-1][j][k-1]
    
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
    
    //そうしてDPのボードが完成したら答えを求める
    //Nの上からi桁目をDとおき、[0,D)だけdp[i][j][k]を足す
    //なお、最後の桁だけは[0,D]
    //Dが0のときは以降の桁に0が残り続けるので、kをデクリメントする
    //全ての桁を調べるかkが負になったら終了
    
    int Ans=0;
    int k=K;
    RREP(i,N.size()){
        int D=N[N.size()-1-i]-'0';
        if(i==0)D++;
        REP(j,D){
            Ans+=dp[i][j][k];
        }
        if(D!=0)k--;
        if(k<0)break;
    }
    cout << Ans << endl;
    
    return 0;
}

