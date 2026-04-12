#include<atcoder/all>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>

#define REP(i,n) for (int i = 0; (i) < (n); ++ (i))
#define FOR(i,n) for (int i = 1; (i) <= (n); ++ (i))
#define dump(x)  cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long

const int INF = 1e18;
const int MOD = 1e9+7;
//const lint LINF = 1e18;
const double eps = 0.000000001;//もとの値の10^(-16)まで

using namespace std;
using namespace atcoder;

//typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
//cout << fixed << setprecision(10) << ans << endl;
//int gcd(int a,int b){return b?gcd(b,a%b):a;}

int op(int a, int b){
    return max(a,b);
}

int e(){
    return -INF;
}

int sankou;
bool f(int x){
    return x < sankou;
} 
signed main(){
    int n,q;
    cin >> n >> q;
    segtree<int ,op ,e> seg(n);
    REP(i,n){
        int a1;
        cin >> a1;
        seg.set(i,a1);
    }
    REP(i,q){
        int q1;
        int q2,q3;
        cin >> q1 >> q2 >> q3;
        if(q1==1){
            seg.set(q2-1,q3);
        }
        if(q1==2){
            cout << seg.prod(q2-1,q3) << endl;
        }
        if(q1==3){
            sankou = q3;
            cout << seg.max_right<f>(q2-1)+1 << endl;
        }

    }
    



    return 0;
}