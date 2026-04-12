#include <iostream>
using namespace std;

int main() {
  while(1){
    int top=0,topn=0,s1[5],s2[5];
    for(int i=0;i<5;i++) {
      cin >> s1[i] >> s2[i];
      if(top<s1[i]+s2[i]) {
        top = s1[i]+s2[i];
        topn = i;
      }
      if(s1[i] == 0 && s2[i] == 0) return 0;
    }
    if(topn == 0) cout << "A ";
    if(topn == 1) cout << "B ";
    if(topn == 2) cout << "C ";
    if(topn == 3) cout << "D ";
    if(topn == 4) cout << "E ";
    cout << top << endl;
  }
}