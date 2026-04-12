#include<bits/stdc++.h>
using namespace std;
char c;
void imput() {
  cin >> c;
}
void judge(char c) {
  if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') cout<<"vowel\n";
  else cout<<"consonant\n";
  return;
}
int main(){
  imput();
  judge(c);
  return 0;
}