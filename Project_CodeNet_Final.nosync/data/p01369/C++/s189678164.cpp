#include<iostream>
#include<string>
using namespace std;

string hidari="qazwsxedcrfvtgb";
string migi="yhnujmifkolp";

int calc(char ch){
  int i;
  for(i=0;i < hidari.size();i++){
    if(ch==hidari[i]){
      return 0;
    }
  }
  return 1;
}

int main(){
  int i;
  string moji;
 
  while(1){
    int count=0;
    cin >> moji;
    if(moji=="#")break;
    int size=moji.size();
    for(i = 0; i+1 < size; i++){
      if( calc(moji[i]) != calc(moji[i+1]))count++;
    }
    
    cout << count << endl;
  }
  return 0;
}