#include <bits/stdc++.h>
using namespace std;
int main(){
  int H, W;
  cin >> H >> W;
  
  vector<string> lines;
  for(int h = 0; h < H; h++){
    string str;
    cin >> str;
    bool ret = false;
    for(int i = 0; i < str.size(); i++){
      if(str.at(i)=='#'){
        ret = true; break;
      }
    }
    if(ret){lines.push_back(str);}
  }
  
  vector<bool> rets(W);
  for(int w = 0; w < W; w++){
    bool ret = false;
    for(int h = 0; h < lines.size(); h++){
    	if(lines.at(h).at(w) == '#'){
          ret = true; break;
        }
  	}
    rets.at(w) = ret;
  }
  
  
  for(int h = 0; h < lines.size(); h++){
    for(int w = 0; w < W; w++){
      if(rets.at(w)){
        cout << lines.at(h).at(w) ;
      }
    }
    cout << endl;
    
  }
  
  return 0;
}