#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
int main(){
  int h,w;
  cin >> h >> w;
  int count = 0;

  for (int i = 1; i<=h; i++){
    for(int j=1; j<=w; j++){
      char c;
      cin >> c;
      if(c == '#'){
        count++;
      }
    }
  }
  if(count == h+w-1){
    cout << "Possible\n";
  }else{
    cout << "Impossible\n";
  }
  return 0;
}