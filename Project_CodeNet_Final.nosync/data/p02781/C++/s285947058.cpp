#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second　//pairの二つ目の要素

int main(){
    int k;
    string s;
    cin>>s>>k;
    int n=s.size();
    ll dp0[n+1][k+1]={},dp1[n+1][k+1]={};
    dp0[0][1]=1; // 丁度の場合
    dp1[0][0]=1; // 0の場合
    dp1[0][1]=s[0]-'0'-1; // それ以外
//    cout<<"1 ";
//    rep(j,k+1)cout<<dp1[0][j]<<" ";
//    cout<<endl;
    for(int i=1;i<n;i++){
      rep(j,k+1){
        if(s[i]!='0') {
            if(j<k) {
              dp0[i][j+1]+=dp0[i-1][j];
            }
          }
        else{
          dp0[i][j]+=dp0[i-1][j];
        }
        // 0が追加
        dp1[i][j]+=dp1[i-1][j];
        if(s[i]!='0') dp1[i][j]+=dp0[i-1][j];
        // 1~9の場合
        if(j<k){
          dp1[i][j+1]+=dp1[i-1][j]*9;
//          rep(j,k+1)cout<<dp1[i][j]<<" ";
//          cout<<endl;      
          if(s[i]!='0') dp1[i][j+1]+=dp0[i-1][j]*(s[i]-'0'-1);
        } 
      }
//        cout<<i<<" ";
//        rep(j,k+1)cout<<dp1[i][j]<<" ";
//        cout<<endl;      
    }
//    cout<<dp1[n-1][k]<<endl;
    cout<<dp0[n-1][k]+dp1[n-1][k]<<endl;
    return 0;
}