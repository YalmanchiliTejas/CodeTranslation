#include<iostream>
using namespace std;

int main(){
  int s1,s2;
  while(cin >> s1 >> s2,s1||s2){
    int ans = 0, val = s1+s2;

    for(int i=1;i<5;i++){
      cin >> s1 >> s2;
      if(val < s1 + s2){
	ans = i;
	val = s1 + s2;
      }
    }
    cout << (char)('A'+ans) << " " << val << endl;
  }
}