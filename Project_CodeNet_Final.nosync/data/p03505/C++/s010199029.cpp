#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define pb push_back
using namespace std;
const int INF = 1e9;
typedef long long ll;

int main(){
  ll k,a,b,res;  
  cin >> k >> a >> b;
  
  if(a <= b && k > a)
    res = -1;
  else if(a <= b && k <= a)
    res = 1;
  else{
    ll one = k/(a-b);
    if((k%(a-b)) != 0)
      one++;
    one *= 2;
    ll two = (k-b)/(a-b);
    if(((k-b)%(a-b)) != 0)
      two++;
    two = 2*two -1;
    ll three = (k+b)/(a-b);
    if(((k+b)%(a-b)) != 0)
      three++;
    three = 2*three +1;
    res = min(one,two);
    res = min(res,three);
  }
  cout  << res << endl;

  return 0;
}

