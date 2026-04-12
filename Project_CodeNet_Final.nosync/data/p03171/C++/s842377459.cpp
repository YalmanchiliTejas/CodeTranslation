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
inline int in() {
    int n, c;
    while ((c = getchar()) < '0') if (c == EOF) return -1;
    n = c - '0';
    while ((c = getchar()) >= '0') n = n * 10 + c - '0';
    return n;
}
ll vec[3000];
int main(){
    int n = in();
    int sz = 0;
    while(n--){
        vec[sz++] = (ll)in();
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
    printf("%lld\n", ans);
}