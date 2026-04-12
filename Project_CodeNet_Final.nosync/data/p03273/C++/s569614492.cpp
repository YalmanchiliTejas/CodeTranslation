#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;


int main(){
  int h,w;cin>>h>>w;
  vector<int> a(h,1),b(w,1);
  string s[h];
  for(int i=0;i<h;i++)cin>>s[i];
  for(int i=0;i<h;i++){
      bool ok=0;
      for(int j=0;j<w;j++){
          if(s[i][j]=='#'){ok=1;break;}
      }
      if(!ok)a[i]=0;
  }
   for(int i=0;i<w;i++){
      bool ok=0;
      for(int j=0;j<h;j++){
          if(s[j][i]=='#'){ok=1;break;}
      }
      if(!ok)b[i]=0;
  }
//  for(int i=0;i<h;i++)if(!a[i])cout<<i<<endl;
  for(int i=0;i<h;i++){
      if(!a[i])continue;
      for(int j=0;j<w;j++){
          if(a[i]&&b[j])cout<<s[i][j];
      }
      cout<<endl;
  }
}