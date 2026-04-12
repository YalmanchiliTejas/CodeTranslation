#include<iostream>
#include<vector>
using namespace std;
int main(void){
  int H,W;
  cin >> H >> W;
  vector<vector<char> > data(H, vector<char>(W));
  
  //入力
  for (int i = 0; i < H;i++){
    for (int j = 0; j < W;j++){
      cin >> data.at(i).at(j);
    }
  }


  //処理
  for (int i = 0; i < H;i++){
    int count =0;
    int count2 = 0;
    for (int j = 0; j < W; j++)
    {
      if(data.at(i).at(j)=='.')
        count++;
      // else
      //   count2++;
    }
    if(count==W){
      for (int j = 0; j < W;j++){
        data.at(i).at(j) = '0';
      }
    }
  }

//処理

  for (int i = 0; i < W;i++){
    int count = 0;
    int count2 = 0;
    for (int j = 0; j < H; j++)
    {
      if(data.at(j).at(i)=='.'||data.at(j).at(i)=='0')
        count++;
      // else
      //   count2++;
    }
    if(count==H){
      for (int j = 0; j < H;j++){
        data.at(j).at(i) = '0';
      }
    }
  }

//cout << "AAAAAAAAA" << endl;

//出力
for (int i = 0; i < H; i++)
{
  int count = 0;
  for (int j = 0; j < W; j++)
  {
   if (data.at(i).at(j) != '0')
    {
      cout << data.at(i).at(j);
      count++;
    }
  }
  //cout << count;
  if (count != 0)
  {
    cout << endl;
  }
  }
  return 0;
}