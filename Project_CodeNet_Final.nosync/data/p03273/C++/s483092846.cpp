#include <bits/stdc++.h>
using namespace std;


int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  int w,l;
  for (int i = 0; i < H; i++) {
    for (size_t j = 0; j <W; j++)
    {
        cin>> a.at(i).at(j);
    }
   }
   
    vector<char> allwhite (W,'.');
    vector<char> allnull (W,'n');
   for (size_t i = 0; i < H; i++)
   {
       if (a.at(i)==allwhite)
       {a.at(i)=allnull;
       }
   };
   
   bool Allwhite=true;
//jは高さ iは横
   for (size_t i = 0; i < W; i++)
   {
       for (size_t j = 0; j < H; j++)
       {
        if(a.at(j).at(i)=='#')
        {Allwhite=false;}
       }
      if(Allwhite)
      {
          for (size_t j = 0; j < H; j++)
          {
            a.at(j).at(i)='n';
          }
      }
      Allwhite="true";
   }

    for (size_t i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
        if(a.at(i).at(j)!='n')
        cout <<a.at(i).at(j);
        if(j==W-1&&a.at(i)!=allnull)
        cout << endl;
            
        }
        
    }
    
}
