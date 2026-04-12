#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define rep(i, n) for(int i = 0; i < (n); i++)

int int_len(int n) {
  int s=0;
  while(n!=0) s++, n/=10;
  return s;
}

int int_sum(int n) {
  int m=0,s=0,a=n;
  while(a!=0) s++, a/=10;
  for(int i=s-1;i>=0;i--) m+=n/((int)pow(10,i))-(n/((int)pow(10,i+1)))*10;
  return m;
}






int gcd(int a,int b)
{
 
  int r, tmp;
 
  
 
  /* 自然数 a > b を確認・入替 */
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
 
  /* ユークリッドの互除法 */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
 
 
 
  return b;
}







int fac(int n){
  int m=1;
  while(n>=1) m*=n,n--;
  return m;
}

int vec_sum(vector<int> v){
  int n=0;
  for(int i=0;i<v.size();i++) n+=v[i];
  return n;
}
///////////////////////////
int main() {
  long long int a,b,c,x,y,ans=0;
  cin>>a>>b>>c>>x>>y;
  if(a+b>2*c){
    ans+=c*min(x,y)*2;
    if(x>=y){
      if(a>=c*2){
        ans+=c*(x-y)*2;
      }else{
        ans+=a*(x-y);
      }
    }else{
      if(b>=c*2){
        ans+=c*(y-x)*2;
      }else{
        ans+=b*(y-x);
      }
    }
    cout<<ans<<endl;
  }else{
    cout<<a*x+b*y<<endl;
  }
  
  
  
}
///////////////////////////

