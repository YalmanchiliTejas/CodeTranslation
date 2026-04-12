#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
//#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
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

int N;
vector<int> A;

const int MEM = 3030;
int dp[MEM][MEM];

int dequeue(int l,int r){
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    if(l>=r){
        return A[l];
    }
    int k = max(A[l]-dequeue(l+1,r),A[r]-dequeue(l,r-1));
    dp[l][r]=k;
    return k;
}

signed main(void){
    int a;
    cin >> N;
    REP(i,N){cin >> a;A.push_back(a);}
    
    REP(i,MEM){
        REP(j,MEM){
            dp[i][j]=-1;
        }
    }
    
    cout << dequeue(0,N-1) << endl;
    
    return 0;
}

