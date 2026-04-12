#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1e9+7
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  vector<string>vs;
  for(int i=0;i<n;i++){
    string s;cin>>s;
    bool flag=true;
    for(int j=0;j<m;j++){
      if(s[j]=='#')flag=false;
    }
    if(flag==false)vs.pb(s);
  }
  vector<string>ans;
  for(int i=0;i<m;i++){
    bool flag=true;
    string s="";
    for(int j=0;j<vs.size();j++){
      if(vs[j][i]=='#')flag=false;
      s+=vs[j][i];
    }
    if(flag==false)ans.pb(s);
  }
  for(int i=0;i<ans[0].size();i++){
    for(int j=0;j<ans.size();j++){
      cout<<ans[j][i];
    }
    cout<<endl;
  }
  return 0;
}
