#include <bits/stdc++.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define s(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
int main(){
  ll A,B,C,X,Y;
  cin >> A>>B>>C>>X>>Y;
  ll all  =10000000000;
  for(ll i=0;i<=200000;i+=2){
    ll ans =0;
    ans += i*C;
    if(i/2<X)ans+=(X-i/2)*A;
    if(i/2<Y)ans+=(Y-i/2)*B;
    all = min(ans,all);
  }
  cout<<all<<endl;

}