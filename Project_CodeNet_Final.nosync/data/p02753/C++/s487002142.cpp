#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i = 0; i < N; i++)
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define cou(x) cout << x << endl
using lint = long long;
int main() {
	string N;
	cin >> N;
	if (N.at(0) == N.at(1) && N.at(1) == N.at(2) && N.at(0) == N.at(2)) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}