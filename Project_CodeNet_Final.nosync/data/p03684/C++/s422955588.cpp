#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int x[100010], y[100010];
pair<int,int> a[100010], b[100010];
vector <pair<int,pair<int,int>> > v;
int par[100010];
int pa(int x){
  if(par[x]==x)
    return x;
  par[x]=pa(par[x]);
  return par[x];
}
void join(int x, int y){
  par[pa(x)]=pa(y);
}
int main(){
  int n, ans;
  while(cin>>n){
    for(int i=0; i<n; ++i){
      scanf("%d%d",&x[i],&y[i]);
      a[i]=mk(x[i],i);
      b[i]=mk(y[i],i);
      par[i]=i;
    }
    sort(a, a+n);
    ans=0;
    for(int i=1; i<n; ++i){
      v.push_back(mk(abs(a[i].fs-a[i-1].fs), mk(a[i].sc, a[i-1].sc)));
    }
    sort(b, b+n);
    for(int i=1; i<n; ++i){
      v.push_back(mk(abs(b[i].fs-b[i-1].fs), mk(b[i].sc, b[i-1].sc)));
    }
    sort(v.begin(), v.end());
    int tmp1, tmp2;
    for(int i=0; i<v.size(); ++i){
      tmp1=v[i].sc.fs;
      tmp2=v[i].sc.sc;
      if(pa(tmp1)==pa(tmp2)){
        continue;
      }
      ans+=v[i].fs;
      join(tmp1, tmp2);
    }
    cout<<ans<<endl;
  }
  return 0;
}



