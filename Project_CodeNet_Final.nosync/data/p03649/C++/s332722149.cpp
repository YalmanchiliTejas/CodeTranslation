#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define forsn(i,s,n) for(int i=(s); i<(int)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define F first
#define S second

typedef long long int tint;
typedef pair<tint, tint> pti;

pti seq[50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	forn(i,n) cin >> seq[i].S;
	forn(i,n) seq[i] = {seq[i].S / n, seq[i].S % n};
	
	tint totalOperations = 0;
	while (max_element(seq, seq + n)->F) {
		tint sum = 0;
		forn(i,n) sum += seq[i].F;
		totalOperations += sum;
		forn(i,n) seq[i] = {(seq[i].S + (sum - seq[i].F)) / n, (seq[i].S + (sum - seq[i].F)) % n};
	}
	cout << totalOperations << "\n";
	
}
