#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w; cin >> h >> w;
  int cnt = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      char a; cin >> a;
      if(a == '#') cnt++;
    }
  }
  if(cnt == h + w -1)
    cout << "Possible";
  else
    cout << "Impossible";
}