#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> C(26, 53);
	for(int i=0; i<n; i++) {
		string S;
		cin >> S;
		sort(S.begin(), S.end());
		char tmp = 'a';
		int tmpi = 0;
		for(int j=0; j<26; j++) {
		    int count = 0;
			while(tmpi < S.size() && S[tmpi] == tmp) {
				count++;
				tmpi++;
			}
			if(C[j] > count) C[j] = count;
			tmp++;
		}
	}
	char tmp = 'a';
	string ret;
	for(int i=0; i<26; i++) {
	   for(int j=0; j<C[i]; j++)
	      ret += tmp;
	   tmp++;
	}
	cout << ret << endl;
	return 0;
}
