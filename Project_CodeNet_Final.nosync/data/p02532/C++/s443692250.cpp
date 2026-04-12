#include<iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	string s[1000],op,v;
	int k;
	while(true) {
		cin >> op;
		if (op == "quit") {
			break;
		} else if (op == "push") {
			cin >> k >> v;
			s[k] += v;
		} else if (op == "pop") {
			cin >> k;
			int lengsmm = (int)(s[k].length())-1;
			cout << s[k].substr(lengsmm,1) << std::endl;
			s[k] = s[k].substr(0,lengsmm);
		} else if (op == "move") {
			int k1,k2;
			cin >> k1 >> k2;
			int lengsmm = (int)(s[k1].length())-1;
			s[k2] += s[k1].substr(lengsmm,1);
			s[k1] = s[k1].substr(0,lengsmm);
		}
	}
}