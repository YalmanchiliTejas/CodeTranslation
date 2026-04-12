#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
  int n,m,ans=0;
  cin >> n>>m;
  vector<int> a(n);
  vector<vector<int>> p(n,vector<int>(n,0));
  rep(i,m){
    int a,b;
    cin>> a>>b;
    a--;b--;
    p[a][b]=p[b][a]=1;
  }
  rep(i,n) a[i]=i;
  do{
        if(a[0]!=0) break;
        bool ok=true;
        rep(i,n-1){
          if(p[a[i]][a[i+1]]==0) ok=false;
        }
        if(ok) ans++;
    } while(next_permutation(a.begin(),a.end()));
    cout<<ans<<endl;
}