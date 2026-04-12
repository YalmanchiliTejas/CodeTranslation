#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

int main(int argc, char const *argv[]) {
  int n,m;cin>>n>>m;
  vector<string> ss(n);
  int num = 0;
  for(int i=0;i<n;++i){
    cin>>ss[i];
    for(int j=0;j<m;++j)num+=(ss[i][j]=='#');
  }
  for(int i=0;i<n*m;++i){
    int x = i/m,y=i%m;
    if(ss[x][y]!='#')continue;
    int tmp = 1;
    while(true){
      int b1=0;
      if(x+1<n&&ss[x+1][y]=='#')b1=1;
      int b2=0;
      if(y+1<m&&ss[x][y+1]=='#')b2=1;
      if(b1+b2!=1)break;
      tmp++;
      if(b1>b2)x++;
      if(b2>b1)y++;
    }
    if(tmp==num){
      std::cout << "Possible" << '\n';
      return 0;
    }
  }
  std::cout << "Impossible" << '\n';
  return 0;
}
