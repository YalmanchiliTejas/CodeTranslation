#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n;
	int vl;
	vector<int> ln[2];
	cin >> n;
	int cs=0;
	for(int i=0;i<n;i++) {
		cin >> vl;
		ln[cs].push_back(vl);
		cs=1-cs;
	}
	for(int i=ln[1-cs].size()-1;i>=0;i--) {
		if(i<ln[1-cs].size()-1) cout << " ";
		cout << ln[1-cs][i];
	}
	for(int i=0;i<ln[cs].size();i++) {
		cout << " " << ln[cs][i];
	}
	cout << endl;
	return 0;
}
