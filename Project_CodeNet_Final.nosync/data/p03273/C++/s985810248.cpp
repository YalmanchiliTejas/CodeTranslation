#include <bits/stdc++.h>
using namespace std;
int H, W;  // H: 縦, W: 横

int main()
{
  cin>>H>>W;
  vector<string> a(H);
  for(int i=0; i<H; i++)  cin>>a[i];
  cout<<endl;

  vector<string> AnsH;
  // 各行をみていく
  for(int i=0; i<H; i++){
    bool b = true;
    for(int j=0; j<W; j++){
      if(a[i][j]=='#'){
        b = false;
        break;
      }
    }
    if(!b){  // b==false -> '#'があったとき
      AnsH.push_back(a[i]);  // AnsH に追加
    }
  }

  vector<int> x(AnsH[0].length(), 1);
  // 各列をみていく
  for(int j=0; j<AnsH[0].length(); j++){
    bool b = true;
    for(int i=0; i<AnsH.size(); i++){
      if(AnsH[i][j]=='#'){
        b = false;
        break;
      }
    }
    if(b){  // b==ture -> '#'がなかったとき
      x[j] = 0;
    }
  }
  
  for(int i=0; i<AnsH.size(); i++){
    for(int j=0; j<AnsH[0].length(); j++){
      if(AnsH[i][j]=='#')  cout<<AnsH[i][j];
      else{
        if(x[j])  cout<<AnsH[i][j];
      }
    }
    cout<<endl;
  }
  return 0;
}
