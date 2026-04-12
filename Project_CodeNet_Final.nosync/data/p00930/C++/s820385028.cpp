

#include<bits/stdc++.h>
using namespace std;
#define int long long
struct starrysky{
  int n;
  starrysky(){}
  starrysky(int n_){init(n_);};
  vector<int> data,datm;
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    data.clear();
    datm.clear();
    data.resize(2*n-1,0);
    datm.resize(2*n-1,0);
  }
  void add(int a,int b,int x,int l,int r,int k){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      data[k]+=x;
      return;
    }
    add(a,b,x,l,(l+r)/2,k*2+1);
    add(a,b,x,(l+r)/2,r,k*2+2);
    datm[k]=min(datm[k*2+1]+data[k*2+1],datm[k*2+2]+data[k*2+2]);
  }
  void add(int a,int b,int x){
    add(a,b,x,0,n,0);
  }
  int query(int a,int b,int l,int r,int k){
    if(r<=a||b<=l) return INT_MAX;
    if(a<=l&&r<=b){
      return data[k]+datm[k];
    }
    return min(query(a,b,l,(l+r)/2,k*2+1),query(a,b,(l+r)/2,r,k*2+2))+data[k];
  }
  int query(int a,int b){
    return query(a,b,0,n,0);
  }
};
#define MAX 333333
string buf;
int dp[MAX],imos[MAX];
signed main(){
  int n,q;
  cin>>n>>q;
  cin>>buf;
  set<int> s;
  for(int i=0;i<n;i++) {
    if(buf[i]=='(') dp[i]=1;
    else dp[i]=-1;
    if(buf[i]==')') s.insert(i);
  }
  imos[0]=dp[0];
  for(int i=1;i<n;i++) imos[i]=imos[i-1]+dp[i];
  starrysky ss(n);
  for(int i=0;i<n;i++) ss.add(i,i+1,imos[i]);
  for(int i=0;i<q;i++){
    int p;cin>>p;p--;
    if(dp[p]==1){
      dp[p]*=-1;
      s.insert(p);
      ss.add(p,n,-2);
      int k=*s.begin();
      s.erase(k);
      dp[k]*=-1;
      ss.add(k,n,2);
      cout<<k+1<<endl;
    }else{
      //cout<<p<<endl;
      dp[p]*=-1;
      s.erase(p);
      ss.add(p,n,2);
      int l=0,r=p;
      while(l+1<r){
	int m=(l+r)/2;
	//cout<<m<<":"<<ss.query(m,n)<<endl;
	if(ss.query(m,n)>=2) r=m;
	else l=m;
      }
      cout<<r+1<<endl;
      dp[r]*=-1;
      s.insert(r);
      ss.add(r,n,-2);
    }
  }
  return 0;
}