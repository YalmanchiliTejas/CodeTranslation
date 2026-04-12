#include<iostream>
#include<cstring>
using namespace std;

char test[2][26] = {
  {'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'},
  {'y','u','i','o','p','h','j','k','l','n','m'}
};

int main(){
  string s;
  while(1){
    cin>>s;
    if(s=="#")break;

    int cnt=0;
    int right=1;
    for(int i=0;i<s.length();i++){
      if(i == 0){
	for(char c:test[0]){
	  if(s[i]==c) right=right^1;
	}
	continue;
      }
      bool flag=false;
      for(char c:test[right]){
	if(s[i]==c)flag=true;
      }
      if(flag==false){
	cnt++;
	right=right^1;
      }
    }
    cout << cnt << endl;
  }
}