#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(obj) (obj).begin(),(obj).end()


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c[3];
  rep(i,3)cin>>c[i];
  if(c[0]==c[1]&&c[0]==c[2])cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  return 0;
}
