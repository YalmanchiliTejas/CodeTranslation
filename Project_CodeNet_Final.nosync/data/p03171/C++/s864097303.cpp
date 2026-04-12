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
int in() {
    int n, c;
    while ((c = getchar()) < '0') if (c == EOF) return -1;
    n = c - '0';
    while ((c = getchar()) >= '0') n = n * 10 + c - '0';
    return n;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<ll>vec;
    while(n--){
        vec.push_back((ll)in());
        int sz = vec.size();
        while(sz >= 3 and vec[sz-1] <= vec[sz-2] and vec[sz-3] <= vec[sz-2]){
            ll a = vec[sz-1] + vec[sz-3] - vec[sz-2];
            rep(i,3)vec.pop_back();
            vec.push_back(a);
            sz-=2;
        }
    }
    ll ans = 0;
    int i = 0, j = vec.size()-1;
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