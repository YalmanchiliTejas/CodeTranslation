#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
#define R(i,n) for(int i = 1; i<=n; i++)
typedef long long ll;
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<int> a(h,0),b(w,0);
  vector<vector<char>> v(h,vector<char>(w,0));
  r(i,h){
    r(j,w){
      cin >> v.at(i).at(j);
      if(v.at(i).at(j)=='#'){
        a.at(i)++; b.at(j)++;
      }
    }
  }
  r(i,h){
    if(a.at(i)>0){
    r(j,w){
      if(b.at(j)>0)cout << v.at(i).at(j);
    }
    cout << endl;
  }
  }
}