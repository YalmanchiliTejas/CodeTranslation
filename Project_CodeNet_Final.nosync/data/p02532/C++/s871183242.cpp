#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<set>
#define PI 3.1415927
using namespace std;

int main(){
  char word; //読み込み文字(色）
  string rule; //命令読み取り
  string mt[101]; //山への積み上げ
  vector<char> ans; //出力結果格納（山からの取り出し）
  int i[101]={},n;
  int mtnum,MTNUM; //山番号
  cin >> n;
  while(1){
    cin >> rule;
    if(rule=="quit") break;
    else if(rule=="push"){
      cin >> mtnum;
      cin >> word;
      mt[mtnum]+=word;
      i[mtnum]++;
    }
    else if(rule=="move"){
      cin >> mtnum;
      cin >> MTNUM;
      mt[MTNUM]+=mt[mtnum][i[mtnum]-1];
      mt[mtnum].erase(i[mtnum]-1);
      i[MTNUM]++;
      i[mtnum]--;
    }
    else if(rule=="pop"){
      cin >> mtnum;
      cout << mt[mtnum][i[mtnum]-1] << endl;
      mt[mtnum].erase(i[mtnum]-1);
      i[mtnum]--;
    }
    
  
  } 

  
  
 return 0;
}