#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false
 
typedef long long ll;
typedef pair<int, int> ii;


bool right(char c){
	if(c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'p' || c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'n' || c == 'm') return true;
	else return false;
}

int main() {

	string s;
	while(cin >> s, s != "#"){
		int ans = 0;
		REP(i, 1, s.size()){
			if(right(s[i-1]) != right(s[i])) ans++;
		}
		cout << ans << endl;
	}

	return 0;
}