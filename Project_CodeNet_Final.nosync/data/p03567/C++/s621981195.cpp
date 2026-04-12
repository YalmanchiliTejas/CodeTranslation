#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s;
	for (int i=0; i<s.size()-1; i++)
		if(s.substr(i,2)=="AC") { cout << "Yes" << endl; return 0; }
	cout << "No" << endl;
	return 0;
}