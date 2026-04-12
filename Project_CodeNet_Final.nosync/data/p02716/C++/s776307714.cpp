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
 
using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

long long s1[200'010];
long long s2[200'010];
long long emax[200'010];

long long dfs(int n, vector<long long>& a, long long now = 0){
  if(n == 1) return now;
  long long res;
  if(n % 2 == 0){
    long long tmp = emax[n-1];
    res = tmp + now;
    return res;
  }
  long long tmp1 = dfs(n - 2, a, now + a[n-1]);
  long long tmp2 = dfs(n - 1, a, now);
  res = max(tmp1, tmp2);
  return res;
}

int main(){
  //using namespace std;
  int n;
  cin>>n;
  vector<long long> a(n);
  REP(i, n) cin>>a[i];
  REP(i, n){
    if(i == 0){
      s1[i] += a[i];
      continue;
    }
    s1[i] = s1[i-1];
    s2[i] = s2[i-1];
    if(i % 2 == 0){
      s1[i] += a[i];
    }else{
      s2[i] += a[i];
    }
  }
  REP(i, n){
    if(i % 2 == 0) continue;
    if(i == 1){
      emax[i] = max(a[0], a[1]);
      continue;
    }
    emax[i] = s1[i];
    emax[i] = max(emax[i], emax[i-2] + a[i]);
  }
  long long ans = dfs(n, a);
  cout<<ans<<endl;
  return 0;
}
