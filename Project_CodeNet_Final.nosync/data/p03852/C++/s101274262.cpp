// Ninjo ~ khaledalam.net@gmail.com
#include <bits/stdc++.h>
using namespace std;
#define sz(A)      (int)(A).size()
#define all(B)     (B).begin(),(B).end()
#define file       freopen("input.txt", "r", stdin)
#define ios        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

set<char> s;

int main() {
//	file;
	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('o');
	s.insert('u');
	char c;
	cin >> c;
	cout << (s.count(c) ? "vowel" : "consonant") << endl;

}
