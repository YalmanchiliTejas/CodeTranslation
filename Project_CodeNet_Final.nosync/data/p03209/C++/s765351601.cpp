#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define int long long

int N, X, h[51], p[51];

void init(){
    cin >> N >> X;
    h[0] = p[0] = 1;
    rep(i,50){
        h[i+1] = 2 * h[i] + 3;
        p[i+1] = 2 * p[i] + 1;
    }
}

int eat(int lv, int x){
    if(x <= 0)     return 0;
    if(h[lv] <= x) return p[lv];
    if(x == 1)     return 0;
    
    int mid = (x-h[lv-1]-1 > 0 ? 1 : 0);
    return eat(lv-1,x-1) + mid + eat(lv-1,x-h[lv-1]-2);
}

signed main(){
    init();
    cout << eat(N,X) << endl;
}