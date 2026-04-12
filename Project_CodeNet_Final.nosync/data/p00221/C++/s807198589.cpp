#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
  int i,j,n,m,k,l,in,t,out;
  string str;
  bool mm[1001];
  while(1){
    cin >> m >> n;
    if(n == 0 && m == 0) break;
    for(i=1;i<=m;i++) mm[i] = 1;
    in = 0;
    out = 0;
    for(i=1;i<=n;i++){
      cin >> str;
      in++;
      if(in > m) in -= m;
      if(out == m - 1) continue;
      while(!mm[in]){
	in++;
	if(in > m) in -= m;
      }

      if(i % 5 == 0 && i % 3 == 0 && str != "FizzBuzz"){
	mm[in] = 0;
	out++;
      }
      else if(i % 3 == 0 && i % 5 != 0 && str != "Fizz" || i % 5 == 0 && i % 3 != 0 && str != "Buzz"){
	mm[in] = 0;
	out++;
      }
      else if(i % 5 == 0 && i % 3 == 0 && str == "FizzBuzz") continue;
      else if(i % 3 == 0 && str == "Fizz" || i % 5 == 0 && str == "Buzz") continue;
      else{
	k = 0;
	j = 1;
	for(l=str.size()-1;l>=0;l--){
	  if(str[l] < '0' && '9' < str[l]){
	    k = -1;
	    break;
	  }
	  else{
	    k += (str[l] - '0') * j;
	    j *= 10;
	  }
	}
	if(i != k){
	   mm[in] = 0;
	   out++;
	}
      }
    }
    
    bool c = true;
    for(i=1;i<=m;i++){
      if(mm[i] && c){
	cout << i;
	c = false;
      }
      else if(mm[i]) cout << " " << i;
    }
    cout << endl;
  }
  return 0;
}