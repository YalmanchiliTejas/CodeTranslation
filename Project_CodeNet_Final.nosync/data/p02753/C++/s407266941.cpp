#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main(void){
  	string s;
  	ll ans = 1;
  	cin >> s;
  	if(s.at(0)==s.at(1)&&s.at(1)==s.at(2))ans=0;
      
      if(ans){
  	cout << "Yes" << endl;
      }
  	else cout << "No" << endl;
}