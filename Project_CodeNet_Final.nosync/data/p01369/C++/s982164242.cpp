#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,j,k;
  int ans;
  string str;
  string left="qazwsxedcrfvtgb";
  string right="yhnujmikolp";

  while(1){
    ans = 0;
    cin >> str;

    int len_str =  str.size()-1;
    int len_right = right.size();
    int len_left = left.size();

    if(str == "#") break;
    for(i = 0 ; i < len_str ; i++){
      for(j = 0 ; j < len_left ; j++){
	for(k = 0 ; k < len_right ; k++){
	  if(str[i]==left[j]&&str[i+1]==right[k]){
	    ans++;
	  }
	}
      }
    }

    for(i = 0 ; i < len_str ; i++){
      for(j = 0 ; j < len_right ; j++){
	for(k = 0 ; k < len_left ; k++){
	  if(str[i]==right[j]&&str[i+1]==left[k]){
	    ans++;
	  }
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}