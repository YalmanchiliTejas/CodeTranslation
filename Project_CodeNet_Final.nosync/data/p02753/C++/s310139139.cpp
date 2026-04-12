#include<bits/stdc++.h>
using namespace std;

#define ioso ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define kholo freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
#define laglo cerr << "Ti : " << clock() * 1.0 / CLOCKS_PER_SEC  << endl;
#define endl '\n';
#define ll long long

int main() {
	ioso; //kholo;
	string s;
	cin >> s;
	if(s[0]==s[1] and s[1]==s[2] and s[0]==s[2]) {
		cout << "No\n";
	}
	else cout << "Yes\n";
	//laglo;
}