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
  
  int h,w;
  cin>>h>>w;
  vector<string> a(h);
  REP(i,h){
    cin>>a[i];
  }
  
  bool rows[h]={};
  bool columns[w]={};
  int valid_n = 0;
  bool flag;
  REP(i,h){
    flag = true;
    REP(j,w){
      if(a[i][j]=='#'){
        flag = false;
        break;
      }
    }
    rows[i] = flag;
    if(!flag)valid_n++;
  }
  REP(j,w){
    flag = true;
    REP(i,h){
      if(a[i][j]=='#'){
        flag = false;
        break;
      }
    }
    columns[j] = flag;
  }
  
  vector<char> ans[valid_n];
  int now = 0;
  REP(i,h){
    if(rows[i])continue;
    REP(j,w){
      if(columns[j])continue;
      ans[now].push_back(a[i][j]);
    }
    now++;
  }
  
  REP(i,valid_n){
    for(char c:ans[i]){
      cout<<c;
    }
    cout<<endl;
  }
  return 0;
}
