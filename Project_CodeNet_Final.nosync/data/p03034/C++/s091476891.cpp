#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
#define ALL(obj) (obj).begin(), (obj).end()
const double PI = acos(-1);
const double EPS = 1e-15;
long long INF=(long long)1E17;
#define i_7 (long long)(1E9+7)
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
using namespace std;
bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}

long long gcd_(long long a, long long b){
  if(a<b){
    swap(a,b);
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

int main(){
  
  int n;
  cin>>n;
  long long s[n];
  REP(i,n){
    cin>>s[i];
  }
  
  long long ans = 0;
  //cはa-bとする
  for(int c = 1; c<=n-2; c++){
    long long score = 0;
    bool visited[n] = {};
    int x = 0;
    while(x*c < n){
      int a = n - 1 - x*c;
      int b = a - c;
      if(a <= 0 || b <= 0)break;
      if(visited[x*c])break;
      visited[x*c] = true;
      if(visited[n-1-x*c])break;
      visited[n-1-x*c] = true;
      score += s[x*c];
      score += s[n-1-x*c];
      ans = max(ans, score);
      x++;
    }
  }
  
  cout<<ans<<endl;
  return 0;
}
