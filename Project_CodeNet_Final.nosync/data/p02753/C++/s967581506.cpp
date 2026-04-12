#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	set<char> s;
	string st;
	cin >> st;
	int n = st.length();
	for(int i = 0;i < n;i++)s.insert(st[i]);
	cout << (s.size() == 2 ? "Yes" : "No");
}
