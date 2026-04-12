#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string s;
  vector<string> a(0);
  for(int i=0; i<H; i++)
  {
    cin >> s;
    for(int j=0; j<W; j++)
      if(s[j]!='.'){
        a.push_back(s);
        break;
      }
  }
  for(int j=0; j<W; j++){
    int wi=0;
    for(int i=0; i<(int)a.size(); i++)
      if(a[i][j]=='.')
        wi++;
    if(wi==(int)a.size())
      for(int i=0; i<(int)a.size(); i++)
        a[i][j]=0;
  }
  for(auto i:a){
    for(auto j:i)
      if(j!=0) cout << j;
    cout << endl;
  }
}
