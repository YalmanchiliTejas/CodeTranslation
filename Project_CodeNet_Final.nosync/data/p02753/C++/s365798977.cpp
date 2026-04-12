#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll inf = 1000000000;
typedef pair<ll, ll> P;
int main() {
	string s;
	cin >> s;
	int kai = 0;
	int kai2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'A') {
			kai++;
			
		}
		if (s[i] != 'B') {
			kai2++;
		}
		
	}
	if (kai == 3||kai2==3) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
}
