#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
  	string s;
  	cin>>s;
  	if (s == "AAA" || s == "BBB") {
      cout<<"No"<<endl;
    } else {
      cout<<"Yes"<<endl;
    }
  	return 0;
}