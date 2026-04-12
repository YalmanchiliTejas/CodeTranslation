#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
 
//#define int ll
 
typedef int64_t ll;
static const int MOD = 1000000007;
//static const int INF = 2147483647;
//static const long long INF = 9223372000000000000;
//static const long long INF = 9223372000000000000/2;
//static const int INF = 1000010000;
//int dx4[4] = {0,0,1,-1}, dy4[4] = {1,-1,0,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define FI first
#define SE second
#define NP next_permutation
#define PQ priority_queue
#define UB upper_bound
#define LB lower_bound
#define SZ(a) signed((a).size())
#define LEN(a) signed((a).length())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).begin(),(c).end());reverse((c).begin(),(c).end());
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REP1(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREP1(i,x) for(int i=((int)(x));i>0;i--)
#define ALL(x) (x).begin(),(x).end()
#define YESNO(x) puts((x)?"YES":"NO")
#define YesNo(x) puts((x)?"Yes":"No")

signed main(){
    int N;
    vector<int> A,B;
    cin >> N;
    REP(i,N){
        int x;
        cin >> x;
        A.PB(x);
        B.PB(x);
    }

    SORT(B);
    int L = B[N/2-1], U = B[N/2];

    if(L==U){
        REP(i,N){
            printf("%d\n",L);
        }
        return 0;
    }

    REP(i,N){
        if(A[i]<=L) printf("%d\n",U);
        else printf("%d\n",L);
    }

    return 0;
}






