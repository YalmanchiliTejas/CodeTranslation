#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;



int main() {
	int n;
	cin >> n;
	vector<string> s(n);


	map<char, int> m;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		
		
	}

	for (char c :s[0]) {
		m[c]++;
	}


	for (int i = 1; i < n;i++) {
		map<char,int> m_tmp;
		for (char c : s[i]) {
			m_tmp[c]++;
		}

		for (int j = 'a'; j <= 'z'; j++) {
			m[j] = min(m[j], m_tmp[j]);
		}
	}
	
	string ans;
	for (auto it = m.begin(); it != m.end(); it++) {
		for (int i = 0; i < it->second;i++) {
			ans += it->first;
		}
	}
	cout << ans << endl;
	
}
