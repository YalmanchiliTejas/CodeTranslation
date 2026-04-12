#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
1 4 2 5 3
ニムトみたいな。一番大きい数の後ろにくっつけてくかんじ
配列すごいたくさん用意する？
1 4 2 5 3
1
4
2 4
2 5
3 5
=2
multisetで、上書きってできんのかな
それできたらいけそう
setの上書きできないのか
vectorならできんの？

あああこれ天才だな。
0判定するために+1の値をおさめてく。
00003
00023
00025
00026
00046
2

*/
int main(){
  ll N; cin>>N;
  vector<ll> M(N,0);
  for(ll i=0; i<N; i++){
    ll a; cin>>a;
    a++;
    auto IT=lower_bound(M.begin(), M.end(), a);
    IT--;//a=2 2未満を満たす最短箇所+1を指し示すぽい。なんで？
    *IT=a;
  }
  cout<<M.end()-lower_bound(M.begin(), M.end(), 1)<<endl;
}