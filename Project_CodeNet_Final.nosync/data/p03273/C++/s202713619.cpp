//wandbox.
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
 
int main() {
cout<<fixed<<setprecision(10);

int H,W;
  cin >> H>> W;
  vector<vector<char>> a(H, vector<char>(W));
  
  for (int i=0;i<H;i++){
    for (int j=0; j<W;j++){
      cin >> a.at(i).at(j);
    }
  }
  
  vector<bool> gyo(H,0);
  for (int i=0;i<H;i++){
    for (int j=0; j<W;j++){
        if(a.at(i).at(j)=='#') gyo.at(i)=1;
    }
  }
  
  vector<bool> retu(W,0);
  for (int j=0;j<W;j++){
    for (int i=0; i<H;i++){
        if(a.at(i).at(j)=='#') retu.at(j)=1;
    }
  }
  
   for (int i=0;i<H;i++){
    if (gyo.at(i)==1){
        for (int j=0; j<W;j++){
         if (retu.at(j)==1){
         cout << a.at(i).at(j);
         }
        }
        cout <<endl;
    }
   }
	
}