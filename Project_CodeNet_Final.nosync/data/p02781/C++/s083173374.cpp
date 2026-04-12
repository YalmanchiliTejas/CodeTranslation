#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define EPS (1e-9)
#define INF (1e17)
#define PI (acos(-1))
//const double PI = acos(-1);
//const double EPS = 1e-15;
//long long INF=(long long)1E17;
#define i_7 (long long)(1e9+7)
//#define i_7 998'244'353
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
long long po(long a, long b){
    if(b==0){
        return 1;
    }
    
    long long z = po(a,b/2);
    z = mod(z*z);
    if(b%2!=0){
        z = mod(a*z);
    }
    return z;
}

bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=std::sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}

long long gcd_(long long a, long long b){
  if(a<b){
    std::swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd_(b,a%b);
  }
}
 
long long lcm_(long long x, long long y){
  return (x/gcd_(x,y))*y;
}

//using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

int main(){
  using namespace std;
  string s;
  cin>>s;
  int k;
  cin>>k;
  int t = s[0] - '0';
  int n = s.size();
  int ans = 0;
  if(k == 1){
    ans = 9 * (n - 1) + t;
    cout<<ans<<endl;
    return 0;
  }
  if(k == 2){
    int index = -1;
    int t2;
    REP(i, n){
      if(i == 0)continue;
      if(s[i] == '0')continue;
      index = i;
      t2 = s[i] - '0';
      break;
    }
    ans = ((n - 1) * (n - 2) / 2) * 9 * 9 + (t - 1) * (n - 1) * 9;
    if(index == -1){
      cout<<ans<<endl;
      return 0;
    }
    ans += t2 + 9 * (n - (index + 1));
    cout<<ans<<endl;
    return 0;
  }
  if(k == 3){
    ans = (((n - 1) * (n - 2) * (n - 3)) / 6) * 9 * 9 * 9 + (t - 1) * ((n - 1) * (n - 2) / 2) * 9 * 9;
    int index = -1;
    int t2;
    REP(i, n){
      if(i == 0)continue;
      if(s[i] == '0')continue;
      index = i;
      t2 = s[i] - '0';
      break;
    }
    if(index == -1){
      cout<<ans<<endl;
      return 0;
    }
    int cnt = n - (index + 1);
    ans += (t2 - 1) * (n - (index + 1)) * 9 + (cnt * (cnt - 1) / 2) * 9 * 9;
    int index2 = -1;
    int t3;
    for(int i = index + 1; i < n; i++){
      if(s[i] == '0')continue;
      index2 = i;
      t3 = s[i] - '0';
      break;
    }
    if(index2 == -1){
      cout<<ans<<endl;
      return 0;
    }
    ans += t3 + 9 * (n - (index2 + 1));
    cout<<ans<<endl;
  } 
  return 0;
}