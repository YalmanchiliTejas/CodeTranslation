#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
int n,tmp;
long long res,res_1,res_2;
vector<int> a,f,r,f_2,r_2;
int main(){
  cin>>n;
  rep(i,n){
    cin>>tmp;
    a.push_back(tmp);
  }
  sort(a.begin(),a.end());
  if(n%2==0){
    rep(i,n){
      if(i<n/2){
        f.push_back(a[i]);
      }else{
        r.insert(r.begin(),a[i]);
      }
    }
    rep(i,f.size()){
      if(i==f.size()-1){
        res-=f[i];
        res+=r[i];
      }else{
        res-=f[i]*2;
        res+=r[i]*2;
      }
    }
  }else{
    rep(i,n){
      if(i<n/2){
        f.push_back(a[i]);
        f_2.push_back(a[i]);
      }
      if(i==n/2){
        r.insert(r.begin(),a[i]);
        f_2.push_back(a[i]);
      }
      else{
        r.insert(r.begin(),a[i]);
        r_2.insert(r_2.begin(),a[i]);
      }
    }
    rep(i,n/2){
      res_1-=f[i]*2;
      res_2+=r_2[i]*2;
    }
    rep(i,n/2+1){
      if(i>=n/2-1){
        res_1+=r[i];
        res_2-=f_2[i];
      }else{
        res_1+=r[i]*2;
        res_2-=f_2[i]*2;
      }
    }
    res=max(res_1,res_2);
  }
  cout<<res;
  return 0;
}
