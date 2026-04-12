#include<bits/stdc++.h>
#define forn(i,n) for(int i = 0; i<n; i++)
#define fi first
#define se second
using namespace std;
string s;
int a, b;
int main(){
	cin >> s;
	forn(i,3){
		s[i] == 'A'? a++: b++;
	}
	if(a&&b) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
