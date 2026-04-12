#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int row[105], col[105];

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

  int h,w;cin>>h>>w;
  string mp[105];
  for(int y=0;y<h;y++){
    cin>>mp[y];
  }
  for(int y=0;y<h;y++){
    for(int x=0;x<w;x++){
      if(mp[y][x]=='#'){row[y]=1;}
    }
  }
  for(int x=0;x<w;x++){
    for(int y=0;y<h;y++){
      if(mp[y][x]=='#'){col[x]=1;}
    }
  }
  for(int y=0;y<h;y++){
    if(!row[y])continue;
    for(int x=0;x<w;x++){
      if(!col[x])continue;
      cout<<mp[y][x];
    }
    cout<<endl;
  }

  return 0;
}
