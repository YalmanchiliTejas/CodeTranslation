#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,x,m,s=0,a,a_,lp=1;cin>>n>>x>>m;
  if(n<=m) {
    s+=x;a=x;
    rep(i,n-1) {
      a_=(a*a)%m;s+=a_;a=a_;
    }
  }
  else {
    lvector v,appeared(m,0);
    s+=x;appeared[x]=1;
    a=x;v.emplace_back(x);
    bool zero=(x==0),one=(x==1);
    rep(i,m+1) {
      a_=(a*a)%m;
      if(appeared[a_]==0) {
        appeared[a_]=1;
        v.emplace_back(a_); 
        s+=a_;a=a_;lp++;
      }
      else break;
      if(a_==0) {zero=true;break;}
      if(a_==1) {one=true;break;}
    }
    if(!zero&&!one) {
      ll t=0,l=v.size(),num=0,pos;
      bool ok=false;
      rep(i,l) {
        if(ok) {t+=v[i];num++;}
        else {if(v[i]==a_) {t+=v[i];num++;pos=i;ok=true;}}
      }
      ll q=(n-lp)/num,rem=(n-lp)%num;
      s+=t*q;
      rep(i,rem) s+=v[pos+i];
    }
    if(!zero&&one) s+=(n-lp);
  }
  print(s);
  return 0;
}