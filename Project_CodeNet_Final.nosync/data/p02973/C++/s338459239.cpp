#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

// Container コンテナ型, map以外
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}

int main(){
  int n; cin >>n;
  vector<int> a(n); rep(i,n) cin >>a[i];
  vector<int> lds;
  reverse(a.begin(),a.end());
  rep(i,n){
    auto itr=upper_bound(lds.begin(),lds.end(),a[i]);
    if(itr==lds.end()) lds.push_back(a[i]);
    else *itr=a[i];
    if(df)print(lds);
  }
  print(lds.size());
}
