#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
typedef long long ll;
typedef long long unsigned int llu;
ll mod = 1000000007;

/*
レベルLバーガーの大きさは、
s[l]=3+2*s[l-1]で計算できる。
レベルLバーガーの下からy層までに含まれるパティの数をp[l][y]で定義する
y=1の時 p[l][y]=0
s[l-1]+1 >= y >= 2の時 p[l][y]=p[l-1][y-1]
y=s[l-1]+2の時 p[l][y]=1+p[l-1][s[l-1]]
y >= 2+s[l-1]の時 p[l][y]=1+p[l-1][s[l-1]]+p[l-1][y-2-s[l-1]]
*/

ll tmp[60];
ll tmp2[60];
ll num(ll i, ll j){
    //cout << "i:" << i << ", j:" << j << endl;
        if(i==0&&j<=0) return 0;
        else if(i==0&&j>=1) return 1;
        else if(j==1) return 0;
        else if(tmp[i-1]+1 >= j && j >= 2) return num(i-1,j-1);
        else if(j==tmp[i-1]+2) return 1+tmp2[i-1];
        else if(2+2*tmp[i-1] >= j && j >= 2+tmp[i-1]) return 1+tmp2[i-1] + num(i-1,j-2-tmp[i-1]);
        else if(3+2*tmp[i-1] == j) return 1+2*tmp2[i-1];
        else return 0;
    }


void solve(){
    ll n,x;
    cin >> n >> x;

    ll s[60];
    s[0]=1;
    for(ll i=1; i<=n; i++){
        s[i]=3 + 2 * s[i-1];
    }
    ll p[60];
    p[0]=1;
    for(ll i=1; i<=n; i++){
        p[i]=1 + 2*p[i-1];
    }

/*
    ll p[n+10][x+10];
    p[0][0]=0;
    p[0][1]=1;
    
    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<x+1; j++){
            if(j==1) {
                p[i][j]=0; 
                cout << "1.i=" << i << ", j=" << j << ", p[i][j]=" << p[i][j] << endl;
            }
            else if(s[i-1]+1 >= j && j >= 2){
                p[i][j]=p[i-1][j-1];
                cout << "2.i=" << i << ", j=" << j << ", p[i][j]=" << p[i][j] << endl;
            }
            else if(j==s[i-1]+2) {
                p[i][j]=1+p[i-1][s[i-1]];
                cout << "3.i=" << i << ", j=" << j << ", p[i][j]=" << p[i][j] << endl;
            }
            else if(2+2*s[i-1] >= j && j >= 2+s[i-1]) {
                p[i][j]=1+p[i-1][s[i-1]] + p[i-1][j-2-s[i-1]];
                cout << "4.i=" << i << ", j=" << j << ", p[i][j]=" << p[i][j] << endl;
            }
            else if(3+2*s[i-1] >= j){
                p[i][j]=1+2*p[i-1][s[i-1]];
                cout << "5.i=" << i << ", j=" << j << ", p[i][j]=" << p[i][j] << endl;
            }
        }
        
    }
    */
    
    rep(i,60){
        tmp[i]=s[i];
        tmp2[i]=p[i];
    }
    cout << num(n,x) << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}