#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= n; ++i)
#define fore(i, l, r) for (int i = l; i <= r; ++i)

using namespace std;
int headlines[52][26];
int final_counts[26];

int main(){
	int n; cin >> n;
	
	
	string s;
	forn(i, n){
		cin >> s;
		for (char c : s){
			int index = (int)(c - 'a');
			headlines[i][index]++; 
		}
	}

	fill(final_counts, final_counts+26, 52);
	
	forn(i, n){
		forn(j, 26){
			final_counts[j] = min(final_counts[j], headlines[i][j]);
		}
	}
	
	forn(i, 26){
		forn(j, final_counts[i]){
			cout << (char)(i + 'a');
		}
	}
}