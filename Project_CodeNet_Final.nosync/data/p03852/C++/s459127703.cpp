#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string vwl="aeiou";
	set<char> st(vwl.begin(), vwl.end());
	char ch; cin>>ch;
	cout << (st.find(ch)!=st.end() ? "vowel" : "consonant") << endl;
	return 0;
}
