#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define MAX 2000000000
#define chmax(a,b) (a<(b)?a=(b),1:0)
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

li even(vector<li>& a){
  int n=a.size();
  li m=0;
  rep(i,n/2){
    m+=a[2*i+1]; // 1,3,5,...,n-1
  }
  li temp=m;
  rep(i,n/2){
    temp+=a[2*i]-a[2*i+1];
    chmax(m,temp);
  }
  return m;
}

li odd(vector<li>& a){
  int n=a.size();
  li m=-a[0],temp=-a[0];
  rep(i,n/2){
    int j=i*2+1;
    temp+=a[j]-a[j+1];
    chmax(temp,-a[j+1]);
    chmax(m,temp);
  }
  li s=0;
  rep(i,n/2+1){
    s+=a[i*2];
  }
  return s+m;
}

int main(){
  int n; cin >>n;
  vector<li> vec(n);
  rep(i,n) cin >>vec[i];
  if(n&1) print(odd(vec));
  else print(even(vec));
}
