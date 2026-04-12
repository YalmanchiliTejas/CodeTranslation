#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,X;
  cin>>N>>X;
  if(N==1){
    if(X<5)
      cout<<X-1<<endl;
    else
      cout<<X-2<<endl;
    return 0;
  }
  //P /-1- /1
  //BPPPB 1-1/-3- (2/3)/3+1*2=5
  //BBPPPBPBPPPBB2-1-1-2/-3-1-3 (6/7)/3+5*2=13
  //BBBPPPBPBPPPBBPBBPPPBPBPPPBBB3-1-1-2-2-1-1-3/-3-1-3-1-3-1-3/ (14/15)3+13*2=29
  //BBBBPPPBPBPPPBBPBBPPPBPBPPPBBBPBBBPPPBPBPPPBBPBBPPPBPBPPPBBBB (30/31)/3+29*2=61
  //4-1-1-2-2-1-1-3-3-1-1-2-2-1-1-4/-3-1-3-1-3-1-3-1-3-1-3-1-3-1-3
  //BBBBBPPPBPBPPPBBPBBPPPBPBPPPBBBPBBBPPPBPBPPPBBPBBPPPBPBPPPBBBBPBBBBPPPBPBPPPBBPBBPPPBPBPPPBBBPBBBPPPBPBPPPBBPBBPPPBPBPPPBBBBB
  //B>P>B
  //総数出しとく。抜粋数に対してどうする？
  //B0P0B=1
  //B1P1B=2
  //B2P2B=3
  //B3P3B=4
  //-----=50
  //2文探索みたいな感じで終了地点を探す。～以下にあるなら総数/2を足してそうじゃないなら範囲狭めるだけ
  vector<ll> Z(N+1,1);
  for(int i=1; i<=N; i++){
    Z[i]=Z[i-1]*2+3;
  }
  ll ans=0, h=Z[N], l=1, mid=(h+l)/2;
  while(1){
    if(mid<=X){
      l=mid;
      ans+=(h-l)/2+1;
    }
    else if(mid>X)
      h=mid;
    l++;
    h--;
    if(l>h)
      break;
    mid=(h+l)/2;
  }
  cout<<ans<<endl;
}