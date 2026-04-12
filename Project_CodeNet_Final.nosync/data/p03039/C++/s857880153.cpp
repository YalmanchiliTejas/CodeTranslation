#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << -1 << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

int BE(int b,int e){
    int r=1;
    while(e){
        if(e&1){
            r=(r*b)%MOD;
        }
        b=(b*b)%MOD;
        e >>=1;
    }
    return r;
}

signed main(void){
    int N,M,K;
    cin >> N >> M >> K;
    int C=1,Ans=0;
    int c=1;
    for(int i=0;i<K-2;i++){
        C=(C*(N*M-2-i))%MOD;
        c=(c*(i+1))%MOD;
    }
    C=(C*BE(c,MOD-2))%MOD;
    int X=0,Y=0;
    for(int d=1;d<=N-1;d++){
        c=(M*M)%MOD;
        c=(c*d)%MOD;
        c=(c*(N-d))%MOD;
        X=(X+c)%MOD;
    }
    for(int d=1;d<=M-1;d++){
        c=(N*N)%MOD;
        c=(c*d)%MOD;
        c=(c*(M-d))%MOD;
        Y=(Y+c)%MOD;
    }
    Ans=(X+Y)%MOD;
    Ans=(Ans*C)%MOD;
    cout << Ans << endl;
  return 0;
}

