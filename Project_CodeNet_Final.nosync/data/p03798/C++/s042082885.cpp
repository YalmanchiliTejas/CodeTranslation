#include <iostream>

using namespace std;
// 1 is sheep
int mem[100005];
int s[100001];
int N;
bool search(int at0, int at1) {
	mem[0] = at0;
	mem[1] = at1;
	for (int i=1; i<N; i++) {
		mem[i+1] = s[i] * mem[i-1] * mem[i];
	}
	
	if (mem[N] == mem[0] && mem[1] == s[0] * mem[N-1]*mem[0]) {
		//clear
		for (int i=0; i<N; i++) {
			cout << ((mem[i]==1)?'S':'W');
		}
		cout << endl;
		return true;
	}
	return false;
}
int main(){
	cin >> N;

	for (int i=0; i<N; i++) {
		char c;
		cin >> c;
		s[i] = c=='o'?1:-1;
	}

	// SS
	if (search(1,1)) {
		return 0;
	}
	// SW
	if (search(1,-1)) {
		return 0;
	}
	// WS
	if (search(-1,1)) {
		return 0;
	}
	// WW
	if (search(-1,-1)) {
		return 0;
	}

	cout << -1 << endl;

	return 0;
}
