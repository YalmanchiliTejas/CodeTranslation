#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);
#define tie cin.tie(0);
#define x first
#define y second
#define ll long long
#define mod 666013

using namespace std;

int n;
string s, rs = "aoieu";


int main(){
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j < rs.size(); j++)
			if (s[i] == rs[j]) return cout << "vowel", 0;
	cout << "consonant";
    return 0;
}
