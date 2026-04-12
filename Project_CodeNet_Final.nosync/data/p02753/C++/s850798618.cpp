#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	string s;
  cin >> s;
  vector<int> v(2,0);
  
  for(int i = 0; i < 3; i++){
    if(s[i] == 'A'){
      v[0]++;
    }
    else
      v[1]++;
  }
	if(v[0] == 3 || v[1] == 3)
      cout << "No" <<endl;
     else
       cout << "Yes" << endl;
  return 0;
}