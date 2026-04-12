#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll int64_t
#define all(v) v.begin(), v.end()


int main() {
  int N,M;
  
  cin >> N >> M ;

  vector<int> a(M);
  vector<int> b(M);

  rep(i,M) cin >> a.at(i) >> b.at(i) ;

  vector<vector<bool>> path(N,vector<bool>(N,false));//パスがあるか

  rep(i,M){
    int X=a.at(i)-1,Y=b.at(i)-1;//パスの指定を1~N→0~N-1に変換
    path.at(X).at(Y)=true;
    path.at(Y).at(X)=true;
  }

  vector<int> order(N);//初期順列の作成
  rep(i,N) order.at(i)=i;//iとすることで、0~N-1で初期化

  int ans=0;

  do{
    if(order.at(0)!=0) continue;//頂点1(ここでは1-1=0)が順列の初めでない場合は飛ばす。
    bool can=true;
    rep(i,N-1){
      int X=order.at(i+1),Y=order.at(i);
      if(!path.at(X).at(Y)) can=false;
    }
    if(can) ans++;

  }while(next_permutation(all(order)));

    cout << ans << endl;
  
  return 0;
}