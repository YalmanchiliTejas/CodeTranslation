#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w; cin>>h>>w;
  vector<vector<char>>A(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>A.at(i).at(j);
    }
  }
  vector<int>H;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
    	if(A.at(i).at(j)=='#'){
          H.push_back(i);
        }
    }
  }
  sort(H.begin(),H.end());
  H.erase(unique(H.begin(),H.end()),H.end());
  vector<vector<char>>B(H.size(),vector<char>(w));
  for(int i=0;i<H.size();i++){
    for(int j=0;j<w;j++){
      B.at(i).at(j)=A.at(H[i]).at(j);
    }
  }
  vector<int>W;
  for(int i=0;i<H.size();i++){
    for(int j=0;j<w;j++){
    	if(B.at(i).at(j)=='#'){
          W.push_back(j);
        }
    }
  }
  sort(W.begin(),W.end());
  W.erase(unique(W.begin(),W.end()),W.end());
  
  vector<vector<char>>C(H.size(),vector<char>(W.size()));
  for(int i=0;i<H.size();i++){
    for(int j=0;j<W.size();j++){
      C.at(i).at(j)=B.at(i).at(W[j]);
    }
  }
  for(int i=0;i<H.size();i++){
    for(int j=0;j<W.size();j++){
      cout<<C.at(i).at(j);
    }
    cout<<endl;
  }
}