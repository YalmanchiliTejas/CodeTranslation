#include <bits/stdc++.h>
using namespace std;

int main() {
  //HW入力
 int H, W;
  cin>>H>>W;
  //行列入力
  vector<vector<char>>letter(H,vector<char>(W)); 
  for(int i=0;i<H;i++)
  {for(int j=0;j<W;j++)
  {cin>>letter.at(i).at(j);}}
  //stringに変換
  vector<vector<string>>letters(H,vector<string>(W));
  for(int i=0;i<H;i++)
  {for(int j=0;j<W;j++)
  {letters.at(i).at(j)=letter.at(i).at(j);}}
  //CompressedGyou定義
  vector<string>CompressedGyou(H);
  //列圧縮の準備
  vector<int>RetsuCounter(W);
  for(int i=0;i<H;i++)
  {for(int j=0;j<W;j++)
  {if (letters.at(i).at(j)=="#")
  {RetsuCounter.at(j)++;}
  }}
  //列圧縮
   for(int i=0;i<H;i++)
   {CompressedGyou.at(i)="";
    for(int j=0;j<W;j++)
    {if(RetsuCounter.at(j)>0){CompressedGyou.at(i)+=letters.at(i).at(j);}}}
     
 string sample="";
 for(int i;i<CompressedGyou.at(0).size();i++)
 {sample+=".";}
     
     for(int i;i<H;i++)
     {if(CompressedGyou.at(i)==sample){}
      else{cout<<CompressedGyou.at(i)<<endl;}
     }
                               
  
  
}