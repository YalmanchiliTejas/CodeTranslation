#include <bits/stdc++.h>
// include <isostream>
using namespace std;
#define _GLIBCXX_DEBUG /GCC環境下で[]による配列要素参照のエラーを出す
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end() //sort(all(vec)); etc
//auto 関数名 = [(&:ラムダ外の引数をとる時))](引数の型1 引数名1, 引数の型2, 引数名2, ...) { 関数の処理 }; //inside main() define function. take care of };
// for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
//   bitset<ビット数> s(tmp);
//   // (ビット列sに対する処理)
// }

int main() {
int n,m;
cin>>n>>m;
#define setint set<int>
set<setint> road;
rep(i,m){
    int a,b;
    cin>>a>>b;
    set<int> s;
    s.insert(a);
    s.insert(b);
    road.insert(s);
}
vector<int> city_(n-1);
rep(i,n-1){
    city_.at(i)=i+1;
}
int sum=0;
do{
  vector<int>city(n);
  city.at(0)=0;
  rep(i,n-1){
    city.at(i+1)=city_.at(i);}
    rep(i,n-1){
        set<int>c;
        c.insert(city.at(i)+1);
        c.insert(city.at(i+1)+1);
        if(!road.count(c)){
           goto SKIP;
        }
    }
  sum+=1;
   SKIP:
   int p;
}while(next_permutation(city_.begin(),city_.end()));
cout<<sum<<endl;
}


