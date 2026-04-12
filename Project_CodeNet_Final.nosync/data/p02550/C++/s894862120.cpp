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

//typedef pair<int, int> P;
//priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
//cout << fixed << setprecision(10) << ans << endl;
//int gcd(int a,int b){return b?gcd(b,a%b):a;}

int kai[300000];
int kotae[300000];


signed main(){
    int n,x,m;
    cin >> n >> x >> m;
    int ans = 0;
    int now = x;
    int nokori = 0;
    for(int i=1;i<=n;i++){
        //cout << "i=" << i << " ans=" << ans << endl;
        ans += now;
        if(kai[now]==0){
            kai[now] = i;
            kotae[now] = ans;
        }
        else{
            int syuuki = i-kai[now];
            int nokosyuuki = (n-i) / syuuki;
            nokori = (n-i)% syuuki;
            int tt = (ans-kotae[now]);
            ans += tt * nokosyuuki;
            now *= now;
            now %= m;
            break;
        }
        now *= now;
        now %= m;
    }
    for(int i=1;i<=nokori;i++){
        ans += now;
        now *= now;
        now %= m;
    }
    cout << ans << endl;
    



    return 0;
}