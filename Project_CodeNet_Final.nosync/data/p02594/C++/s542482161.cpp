#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pci pair<char, int>
#define pic pair<int, char>
#define plvl pair<long long, vector<long long> >
#define pcvc pair<char, vector<char> >
#define mod 1000000007
#define newl "\n"

using namespace std;

ll gcd(ll a, ll b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

template <typename T>
void show1(vector<T> dp) {
	for(auto d : dp) {
		cout << d << " ";
	}
	cout << "\n";
}

template <typename T>
void show2(vector<vector<T> > dp) {
	for(auto d : dp) {
		for(auto dd : d) {
			cout << dd << " ";
		}
		cout << "\n";
	}
}

void executeCode() {
	ll x;
	cin >> x;
	cout << (x >= 30 ? "Yes" : "No") << newl;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = 1;
	// cin >> tt;
	for(ll i = 1; i <= tt ; i++) {
	//	cout << "Case #" << i << ": ";
		executeCode();	
	}
	return 0;
}