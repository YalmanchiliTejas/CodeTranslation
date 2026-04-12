#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <climits>
#include <unordered_map>
#include <numeric>
#include <cstring>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
typedef long long ll;
typedef pair<int,int> pii;
inline int getint() {
	register char ch;
	while(!isdigit(ch=getchar()));
	register int x=ch^'0';
	while(isdigit(ch=getchar())) x=(((x<<2)+x)<<1)+(ch^'0');
	return x;
}
ll vec[3000];
int main(){
    int n = getint();
    int sz = 0;
    while(n--){
        vec[sz++] = (ll)getint();
        while(sz >= 3 and vec[sz-1] <= vec[sz-2] and vec[sz-3] <= vec[sz-2]){
            vec[sz-3] = vec[sz-1] + vec[sz-3] - vec[sz-2];
            sz-=2;
        }
    }
    ll ans = 0;
    int i = 0, j = sz-1;
    int k = 1;
    while(i<=j){
        if(vec[i] > vec[j]){
            ans += vec[i]*k;
            i++;
        }else{
            ans += vec[j]*k;
            j--;
        }
        k *= -1;
    }
    printf("%lld", ans);
}