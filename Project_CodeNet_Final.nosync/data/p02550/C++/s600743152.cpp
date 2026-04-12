#include<bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;
// using namespace atcoder;

const ll mod=1000000007;//998244353;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

vector<vector<ll>> bunkai(ll a){
  if(a<=0) return {};
  if(a==1) return {{1,1}};
  vector<ll> f;
  ll b=a;
  for(ll i=2;i*i<=a;i++){
    if(b%i==0){
      f.push_back(i);
      b=b/i;
      i--;
    }
  if(b==1)break;
  }
  if(b!=1)f.push_back(b);

  vector<vector<ll>> u;
  ll p=f[0];
  ll c=1;
  for(ll i=1;i<f.size();i++){
    if(f[i]==p)c++;
    else{
      u.push_back({p,c});
      p=f[i];
      c=1;
    }
  }
  u.push_back({p,c});

  return u;
}

vector<ll> yakusu(ll a){
  if(a<=0)a=-a;
  if(a==1) return {1};
  vector<ll> f={1,a};
  for(ll i=2;i*i<=a;i++){
    if(a%i==0 && i*i!=a){
      f.push_back(i);
      f.push_back(a/i);
    }
    if(i*i==a)f.push_back(i);
  }
  sort(f.begin(),f.end());

  return f;
}

int main(){

  ll n,x,m;
  cin >> n >> x >> m;

  if(x==0)cout << 0 << endl;
  else if(x==1)cout << n << endl;
  else{
    mat u=bunkai(x),v=bunkai(m);
    vec h,w;
    for(ll i=0;i<u.size();i++)h.push_back(u[i][0]);
    for(ll i=0;i<v.size();i++)w.push_back(v[i][0]);
    bool ok=1;
    for(ll i=0;i<w.size();i++){
      ll e=w[i];
      if(lower_bound(h.begin(),h.end(),e)==upper_bound(h.begin(),h.end(),e))ok=0;
    }
    if(ok){
      ll ans=0;
      ans+=x;
      while(x!=0){
        x=x*x%m;
        ans+=x;
      }
      cout << ans << endl;
    }
    else{
      ll y=x;
      ll ans=0;
      ll p=x;//1周の和
      ll c=1;//1周の長さ
      vec s(m+1);
      s[x]=1;
      ll ok=false;
      while(!ok){
        x=x*x%m;
        if(s[x]==0){
          s[x]=1;
          p+=x;
          c++;
        }
        else{
          ok=true;
        }
      }
      if(y==x){
        ans+=p*(n/c);
        ll q=n%c;
        x=y;
        if(q>0)ans+=x;
        for(ll i=0;i<q-1;i++){
          x=x*x%m;
          ans+=x;
        }
        cout << ans << endl;
        return 0;
      }
      ok=false;
      ans+=y;
      ll d=1;
      while(y!=x){
        y=y*y%m;
        if(y!=x){
          ans+=y;
          d++;
        }
      }
      n-=d;
      p=y;
      c=1;
      while(!ok){
        x=x*x%m;
        if(x!=y){
          p+=x;
          c++;
        }
        else ok=1;
      }
      ans+=p*(n/c);
      ll q=n%c;
      x=y;
      if(q>0)ans+=x;
      for(ll i=0;i<q-1;i++){
        x=x*x%m;
        ans+=x;
      }
      cout << ans << endl;

      //cout << c  <<" " << q << " " << n/c << " " << p << " " << x << endl;
    }
  }

  return 0;
}