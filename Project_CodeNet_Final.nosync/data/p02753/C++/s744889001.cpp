#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
string s;
int cnt = 0;
cin >> s;
for (int i = 0; i < 3; i++){
  if (s[i] == 'A'){
    cnt ++;
  }
  else{
    cnt --;
  }
}
if (cnt == 3 || cnt == -3){
  cout << "No\n";
}
if (cnt != 3 && cnt != -3){
  cout << "Yes\n";
}
return 0;   
}