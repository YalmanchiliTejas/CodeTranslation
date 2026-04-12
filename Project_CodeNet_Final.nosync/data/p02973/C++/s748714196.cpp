#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,a;
  multiset<int> s;
  cin>> n;
  for (int i=0; i<n; i++){
    cin>> a;
    s.insert(a);
    auto itr=s.lower_bound(a);
    if (itr!=begin(s)) s.erase(--itr); //値指定は一致した値全て消去する。単一要素の削除ならイテレータ指定が良い。
  }
  cout<< s.size() <<endl;
}