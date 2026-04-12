#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	string s, s1 = "AC";
	cin >> s ;
		int flag = 0;
		for(int i = 0; i <s.size(); i++){
			string ss;
			ss.clear();
			for (int j = i,k = 1; k <=2; k++, j++)
				ss += s[j];
			if(ss == s1) flag = 1;
		}
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	return 0;
}