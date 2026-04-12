#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;

ll cal(int n, ll x) {
    if(n==0 && x==1) return 1;
    /*漸化式は自分で解く
    a(0)=1, a(n+1)=2*a(n)+3
    →a(n)=2^(n+2)-3
    同様に、b(n)=2^(n+1)-1*/
    ll sum=(1LL<<(n+1))-3, p=(1LL<<n)-1; //a(n-1),b(n-1)
    if(x<=1) return 0;
    else if(x<=sum+1) return cal(n-1, x-1); //半分未満
    else if(x<sum*2+3) return p+1+cal(n-1, x-sum-2); //半分以上全部未満
    else return p*2+1;
}

int main(){
  int n;
  ll x;
  cin >> n >> x;
  cout << cal(n,x) << endl;
  return 0;
}