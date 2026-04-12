#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main(){
  int h,w,cnt=0;
  vector<pair<int,int>> list;
  cin >> h >> w;
  string a[h];
  for(int i=0;i<h;i++){
    cin >> a[i];
    for(int j=0;j<w;j++){
      if(a[i][j]=='#')cnt++;
    }
  }
  if(cnt==w+h-1)cout << "Possible\n";
  else cout <<"Impossible\n";
}
