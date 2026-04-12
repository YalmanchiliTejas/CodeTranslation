#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <bitset>
#include <stack>
#include <cassert>
using namespace std;
typedef long long LL;
const int M = 1e6 + 5;
const int N = 3e5 + 5;
const LL mod = 19260817;
const int MAX = 5e5 + 5;
const int MAXV = 100000 + 5;
const LL INF = (1LL << 62);
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.);
const int limit = 4;
int a[N];
int main() {
#ifdef local
    freopen("input", "r", stdin);
//    freopen("w", "w", stdout);
//    freopen("input", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)cin>>a[i];
    if(n&1){
        cout<<a[n];
        for(int i = n - 2; i >= 1; i -= 2){
            cout<<" "<<a[i];
        }
        for(int i = 2; i <= n; i += 2){
            cout<<" "<<a[i];
        }
        cout<<endl;
    }
    else {
        for(int i = n; i >= 1; i -= 2){
            cout<<a[i]<<" ";
        }
        for(int i = 1; i <= n; i += 2){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}

