#include<iostream>
using namespace std;

int main(){
  string s;
  int c;
  bool tmp,a[] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0};

  while(1){
    cin >> s;
    if(s == "#")break;

    tmp = a[s[0]-'a'];
    c = 0;
    for(int i=1;i<s.size();i++){
      if(tmp != a[s[i]-'a']){
	c++;
	tmp = 1 - tmp;
      }
    }

    cout << c << endl;
  }
}