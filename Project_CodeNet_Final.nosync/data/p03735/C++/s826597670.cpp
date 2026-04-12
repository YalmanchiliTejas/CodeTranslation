#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<ll> x,y;
  ll Rmax=0,mi=1e10;
  int mat=0;
  for(int i=0;i<n;i++){
    ll a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    x.push_back(a);
    y.push_back(b);
    if(Rmax<b){
      Rmax=b;
      mat=i;
    }
    mi=min(mi,a);
  }

  ll ansDif=0;
  ll Rmin=Rmax,Bmin=mi,Bmax=x[mat];
  for(int i=0;i<n;i++){
    Bmin=min(Bmin,x[i]);
    Rmin=min(Rmin,y[i]);
    Bmax=max(Bmax,x[i]);
  }
  ansDif=(Rmax-Rmin)*(Bmax-Bmin);
  //cout<<ansDif<<endl;

  ll ansSame=ansDif;
  Rmin=mi;Bmin=1e10;
  vector<pair<ll,ll>> v;
  for(int i=0;i<n;i++){
    v.push_back(make_pair(x[i],y[i]));
  }
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++){
    Bmin=min(Bmin,v[i].second);
    Bmax=max(Bmax,v[i].second);
    if(i==n-1) ansSame=min(ansSame,(Rmax-Rmin)*(Bmax-Bmin));
    else{
      ansSame=min(ansSame,(Rmax-Rmin)*(Bmax-(min(Bmin,v[i+1].first))));
    }
  }

  cout<<min(ansSame,ansDif)<<endl;
  return 0;
}
