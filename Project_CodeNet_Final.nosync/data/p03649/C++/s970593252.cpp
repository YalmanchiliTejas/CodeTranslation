#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int MAX_N = 1<<18;
const int N = MAX_N;
const int INF = 1LL<<55;
int Max(int &a,int b){return a=max(a,b);}
int Min(int &a,int b){return a=min(a,b);}

class RSQ2{
public:
  ll n;
  vector<ll> dat,td;
  //初期化
  RSQ2(){
    dat.resize(MAX_N*2 - 1,0);
    td.resize(MAX_N* - 12,0);
    n=MAX_N;
  };
  RSQ2(int n_){
    n=1;
    while(n<n_)n*=2; //要素数nを2のべき乗に
    dat.resize(n*2- 1, 0);
    td.resize(n*2 - 1, 0);
  }
  
  //[a,b)の区間にxを加算する,query(a,b,x);
  ll add(int a,int b,ll x,int k=0,int l=0,int r=-1){
    if(r==-1) r=n;
    if(r<=a||b<=l)return 0;
    if(a<=l&&r<=b){
      dat[k]+=(r-l)*x; 
      td[k]+=x;
      return dat[k];
    }

    dat[k]+=(min(r,b)-max(l,a))*x;
    ll kl=k*2+1,kr=k*2+2,t=td[k]*(r-l)/2;
    dat[kl]+=t, dat[kr]+=t;
    td[kl]+=td[k], td[kr]+=td[k];
    td[k]=0;

    ll vl=add(a,b,x,k*2+1,l,(l+r)/2);
    ll vr=add(a,b,x,k*2+2,(l+r)/2,r);
    return vl+vr;
  }
  
  //[a,b)の総和を得る
  ll sum(int a,int b){return add(a,b,0);}
};

int A[N],n;


int solve(){
  RSQ2 T(n);
  for(int i=0;i<n;i++) T.add(i,i+1,A[i]);
  int sum  = 0;
  while(1){
    int psum = sum;
    for(int i=0;i<n;i++){
      int s = T.sum(i,i+1)/n;
      if(s == 0)continue;
      sum += s;
      T.add(0,n,s);
      T.add(i,i+1, -s*n - s);
    }
    if(psum == sum) return sum;
  }
}


signed main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>A[i];

  cout<<solve()<<endl;
  return 0;
}
