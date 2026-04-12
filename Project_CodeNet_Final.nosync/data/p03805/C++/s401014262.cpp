#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int g[10][10];

int main(int argc, char *argv[]) { ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int n,m;cin>>n>>m;
for(int i=0;i<m;i++){
  int a,b;cin>>a>>b;a--,b--;
  g[a][b]=1;g[b][a]=1;
}
vector<int> v(n);
for(int i=0;i<n;i++)v[i]=i;
int ans=0;
do{
  bool ok=true;
  if(v[0]!=0)continue;
  for(int i=0;i<n-1;i++){
    int a = v[i];int b = v[i+1];
    if(!g[a][b])ok=false;
  }
  if(ok)ans++;
} while(next_permutation(v.begin(), v.end()));
  cout<<ans<<endl;
  return 0;
}
