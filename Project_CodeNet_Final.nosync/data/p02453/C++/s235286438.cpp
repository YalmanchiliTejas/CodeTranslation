#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
using namespace std;
#define MM 1000000000
#define MOD MM+7
#define pi pair<int32,int32>
#define pl pair<int64,int64>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T lcm(T x,T y){
    return x*y/GCD(x,y);
}
long long Pow(long long base,long long x){
    if (x == 0) return 1;
    if (x%2 == 1) return (base*Pow(base,x-1))%MOD;
    long long y = Pow(base, x/2);
    return y*y%MOD;
}

int main(){
    long long n,q; cin >> n;
    vector<long long> a(0);
    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        a.push_back(num);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        long long k; cin >> k;
        cout << lower_bound(a.begin(), a.end(), k) - a.begin() << endl;
    }
}
  


