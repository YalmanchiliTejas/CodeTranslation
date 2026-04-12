#include <bits/stdc++.h>
using namespace std;

int main(){

  string n;

  while(cin >> n){

    if(n == "#") break;

    string QWERTY[2] = {"yuiophjklnm","qwertasdfgzxcvb"};
    int judge[32] = {0};
    int cnt = 0, count = 0;

    for(int i = 0; i < (int)n.size(); i++){
      for(int j = 0; j < (int)QWERTY[0].size(); j++){
	if(n[i] == QWERTY[0][j]){
	  judge[i] = 1;
	  //cout << QWERTY[0][j];
	}
      }
      for(int j = 0; j < (int)QWERTY[1].size(); j++){
	if(n[i] == QWERTY[1][j]){
	  judge[i] = 2;
	  // cout << QWERTY[1][j];
	}
      }
    
    
    
    }

    cnt = judge[0];
    for(int k = 1; k < (int)n.size(); k++){
      if(cnt != judge[k]){
	cnt = judge[k];
	count++;
      }
    }
	    
    cout << count << endl;
    count = 0;


  } 

  return 0;
}