#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <complex>
#define LL long long
using namespace std;
const int M = 1e3 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1);
const LL MAX=1e16+1000;
LL A[M];
int main() {
    LL n;
    while(cin>>n){
        for(int j=1;j<=n;j++){
            scanf("%lld",&A[j]);
        }
        LL ans=0;
        while(1){
            pair<LL,int> maxx={0LL,0};
            for(int j=1;j<=n;j++){
                pair<LL,int> now={A[j],j};
                maxx=max(maxx,now);
            }
            if(maxx.first<n) break;
            for(int j=1;j<=n;j++){
                if(j!=maxx.second) A[j]+=maxx.first/n;
                else A[j]=maxx.first%n;
            }
            ans+=maxx.first/n;

        }
        printf("%lld\n",ans);
    }
    return 0;
}
