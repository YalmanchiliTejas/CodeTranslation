#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define p(s) cout<<(s)<<endl
#define REP(i,n,N) for(int i=n;i<N;i++)
#define RREP(i,n,N) for(int i=N-1;i>=n;i--)
#define CK(n,a,b) ((a)<=(n)&&(n)<(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const int inf = 1e9+7;
ll N,K;
ll ans;
int main() {
    cin>>N>>K;
    if(K==0) ans=N*N;
    else {
        REP(j, K + 1, N + 1) {
            ans += ((N - K) / j) * (j - K);
            ans += min((j - K), (N - K) % j + 1);
        }
    }
    p(ans);
    return 0;
}