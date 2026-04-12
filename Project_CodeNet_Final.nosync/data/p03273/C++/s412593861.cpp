#include <iostream>
#include <vector>
using namespace std;

int main()
{
  //変数の準備
  int h, w;
  cin >> h >> w;
  string S[h];
  string s;
  bool isBrankLine[h] = {false};
  bool isBrankCol[w];
  for(int i = 0; i < w; i++)
    isBrankCol[i] = true;
  
  //入力
  for(int i = 0; i < h; i++)
  {
    cin >> s;
    S[i] = s;
    if(s.find('#') == string::npos)
      isBrankLine[i] = true;
    else
    {
      for(int j = 0; j < w; j++)
      {
        if(isBrankCol[j] && s[j] == '#')
          isBrankCol[j] = false;
      }
    }
  }
  
  //出力
  for(int i = 0; i < h; i++)
  {
    if(!isBrankLine[i])
    {
      for(int j = 0; j < w; j++)
      {
        if(!isBrankCol[j])
          cout << S[i][j];
      }
      cout << endl;
    }
  }
  
  return 0;
}