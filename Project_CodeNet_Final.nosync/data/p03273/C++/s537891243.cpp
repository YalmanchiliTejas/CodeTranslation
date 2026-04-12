#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool okH[105], okW[105];
string mp[105];

int main(int argc, char *argv[]) { ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int h,w;cin>>h>>w;
for(int i=0;i<h;i++){
  cin>>mp[i];
  for(int j=0;j<w;j++){
    if(mp[i][j]=='#'){
      okH[i]=1;
      okW[j]=1;
    }
  }
}
for(int i=0;i<h;i++){
  if(!okH[i])continue;
  bool f=false;
  for(int j=0;j<w;j++){
    if(!okW[j])continue;
    cout<<mp[i][j];
    f=true;
  }
  if(f)cout<<endl;
}
  
  return 0;
}
