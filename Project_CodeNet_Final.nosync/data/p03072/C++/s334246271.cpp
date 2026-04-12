#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n ; ++i)
#define REP(i,a,b) for(int i=a; i<b; ++i)
typedef long long ll;
//プロトタイプ宣言
int gcd(int , int);


int main(){
    int n,ans = 0;
    cin >> n;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];
    }
    rep(i,n){
        bool flag = true;
        for(int j = 0; j < i ; ++j){
            if(h[i]<h[j]) flag = false;
        }
        if(flag) ++ans;
    }
    cout << ans << endl;
}








































//以下、ライブラリ
//ユークリッドの互除法

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}