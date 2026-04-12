#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  char left[]={'q','a','z','w','s','x','e','d','c','r','f','v','t','g','b'};
  char right[]={'y','h','n','u','j','m','i','k','o','l','p'};
  int flag=2;
  int cnt;

  while(1){
    
    cin >> str;
    if(str == "#") break;
    cnt=0;
    flag=2;
    
    for(int i=0;i < str.size();i++){

      for(int j=0;j < 15;j++){
	if(str[i] == left[j]){
	  if(flag == 1) cnt++;
	  flag=0;
	}
      }
      for(int j=0;j < 11;j++){
	if(str[i] == right[j]){
	  if(flag == 0) cnt++;
	  flag=1;
	}
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

