#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >>h>>w;
  vector<vector<char>> data(h,vector<char>(w));
  vector<int>height(h);
  vector<int>weight(w);
  for(int i=0;i<h;i++)
    for(int k=0;k<w;k++){
      cin>>data.at(i).at(k);
      if(data.at(i).at(k)=='#'){height.at(i)++;weight.at(k)++;}
    }
  for(int i=0;i<h;i++)
    for(int k=0;k<w;k++){
      if(height.at(i)!=0 && weight.at(k)!=0)
        cout<<data.at(i).at(k);
      if(k==w-1 && height.at(i)!=0) cout<<endl;
    }
}
