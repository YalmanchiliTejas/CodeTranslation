#include<iostream>
#include<string>
using namespace std;

int main(){
  int i,j,k;
  string moji;
  string hidari="qazwsxedcrfvtgb";
  string migi="yhnujmikolp";

  while(1){
    int count=0;
    cin >> moji;
    if(moji=="#")break;
    for(i = 0; i < moji.size()-1; i++){
      for(j = 0; j < hidari.size(); j++){
	for(k = 0; k < migi.size(); k++){
	  if(moji[i]==hidari[j] && moji[i+1]==migi[k])count++;
	}
      }
    }

    for(i = 0; i < moji.size()-1; i++){
      for(j = 0; j < migi.size(); j++){
	for(k = 0; k < hidari.size(); k++){
	  if(moji[i]==migi[j] && moji[i+1]==hidari[k])count++;
	}
      }
    }
   
    cout << count << endl;
  }
  return 0;
}