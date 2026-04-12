#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long int ll;
ll s[51];
ll p[51];
ll pt(ll a,ll b);
int main(){
  ll n,x;
  cin >> n>>x;
  s[0]=1;//層の数
  p[0]=1;//全体のパティの数
  for(int i=1;i<50;i++){
    s[i]=s[i-1]*2+3;
    p[i]=p[i-1]*2+1;
  }
  cout <<pt(n,x)<<endl;
}
ll pt(ll a,ll b){//levelaのb層目までもパティの数
  if(a==0) {
  if(b<=0) return 0;
  else return 1;
}
  if(1+s[a-1]>=b) return pt(a-1,b-1);//最初のバーガーの前
  if(b==2+s[a-1]) return p[a-1]+1;//パティまで到達
  if(2+s[a-1]<b&&b<=2+2*s[a-1]) return p[a-1]+1+pt(a-1,b-1-s[a-1]-1);//次のバーガー
  if(b==3+2*s[a-1]) return 2*p[a-1]+1;//最後まで到達
}
