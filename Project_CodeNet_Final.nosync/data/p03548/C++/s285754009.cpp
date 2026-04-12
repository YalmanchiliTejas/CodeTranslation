#include<bits/stdc++.h>

using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using vs=vector<string>;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define rep(i, a, n) for (int i = (n); i < (a); ++i)
#define repr(i, a, n) for (int i = (n); i >= (a); --i)

template<typename T,typename U>
void Inparray(T &f,U n){
  for(int i=0;i<n;i++) cin>>f[i];
}

template<typename T,typename U>
void Printarray(T f,U n){
  for(int i=0;i<n;i++) i!=n ? cout<<f[i]<<" " : cout<<f[i];
}

void flagfunc(bool flag,string A,string B){
  flag ? cout<<A<<endl : cout<<B<<endl;
}

void flag2func(bool flag){
  flag ? cout<<"Yes"<<endl : cout<<"No"<<endl;
}

void flag3func(bool flag){
  flag ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}

int main(){
  cin.tie(nullptr);ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int x,y,z;cin>>x>>y>>z;
  int num=y+2*z,ans=0;
  while(1)
  {
  	if(num>x)break;
  	num+=y+z;
  	ans++;
  }
  cout<<ans<<endl;
}
