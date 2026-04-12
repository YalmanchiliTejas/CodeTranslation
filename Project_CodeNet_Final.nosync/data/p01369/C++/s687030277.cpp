#include<iostream>
//#include<set>

using namespace std;

int main() {
  string left = "qwertasdfgzxcvb";
  string right = "yuiophjklnm";
  string str;
  while(cin>>str && str!="#") {
    int cnt = -1;
    string nowHand = "none";
    string lastHand = "none";
    for(int i=0; i<str.size(); i++) {
      bool flag = false;
      for(int j=0; j<right.length() && flag==false; j++) {
	if(str[i] == right[j]) {
	  lastHand = nowHand;
	  nowHand = "right";
	  flag = true;
	}
      }
      if(flag == false) {
	lastHand = nowHand;
	nowHand = "left";
      }
      if(lastHand != nowHand) {
	cnt++;
      }
    }
    cout<<cnt<<endl;
  }
}