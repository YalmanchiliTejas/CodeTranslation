#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
ll N,X;
ll num1[51], num2[51];//サイズ　パティの数
//depth index
ll cnt(ll d, ll ind){
    //cout << d << " " << ind << endl;
    if(d == 0)return 1;
    if(ind == 1)return 0;
    if(ind == num1[d-1] + 2)return num2[d-1] + 1;
    if(ind == num1[d-1] * 2 + 3)return num2[d];

    if(ind < num1[d-1] + 2)return cnt(d-1, ind-1);
    else                 return cnt(d-1, ind - num1[d-1] - 2) + num2[d-1] + 1;
}
main(){
    cin >> N >> X;
    num1[0] = num2[0] = 1;
    rep(i,0,N){
        num1[i+1] = num1[i] * 2 + 3;
        num2[i+1] = num2[i] * 2 + 1;
    }
    
    //rep(i,0,N+1)cout << num1[i] << " " << num2[i] << endl;
    //cout << endl;
    cout << cnt(N, X) << endl;

}