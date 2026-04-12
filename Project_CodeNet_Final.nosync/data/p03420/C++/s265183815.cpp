#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include<utility>
#include<cmath>
#include<set>
#include<list>
#include<string>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<set>
#include<cstring>
#include<iterator>
#include<bitset>
#include<assert.h>
//#include<chrono>
//#include<time.h>
//#include<windows.h>
using namespace std;
 
#define int ll
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef vector<int> VI;
typedef vector<long long int> VL;
static const int MOD = 1000000007;
//static const int INF = 2147483647;
//static const long long INF = 9223372000000000000;
//static const long long INF = 9223372000000000000/2;
//static const int INF = 1000010000;
//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define FI first
#define SE second
#define NP next_permutation
#define PQ priority_queue
#define UB upper_bound
#define LB lower_bound
#define SZ(a) int((a).size())
#define LEN(a) int((a).length())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REP1(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREP1(i,x) for(int i=((int)(x));i>0;i--)
#define ALL(x) (x).begin(),(x).end()
#define YESNO(x) puts((x)?"YES":"NO")
struct edge {int /*from,*/to,cost;};

signed main(){
    int n,k;
    cin >> n >> k;
    if(k==0){
        printf("%lld\n",n*n);
        return 0;
    }

    int ans = 0;
    FOR(i,k+1,n+1){
        ans += (n/i) * (i-k);
        ans += max(0ll,(n%i)-k+1);
        //printf("b=%lldのとき:%lld\n",i,max(0ll,(n%i)-k+1)+(n/i) * (i-k));
    }

    printf("%lld\n",ans);

    return 0;
}
