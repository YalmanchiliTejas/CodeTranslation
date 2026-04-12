#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;cin>>n;
	string s;cin >>s;
	int k;cin >>k;
	string out = "";
	string target = s.substr(k-1,1);
	for(int i=0;i<n;++i){
		auto tmp = s.substr(i,1);
		if(tmp == target){
			out +=tmp;
		} else {
			out +="*";
		}
	}
	cout << out << endl;
	return 0;
}