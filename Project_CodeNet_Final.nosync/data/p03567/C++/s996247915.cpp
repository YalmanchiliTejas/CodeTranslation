#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n) FOR(i,0,n)
 
int main(){
	
	string s;cin >> s;
	rep(i,s.size()-1)
	{
		if(s[i] == 'A' and s[i+1]=='C')
		{
			cout << "Yes" <<endl;
			return 0;
		}
	}
	cout << "No" <<endl;
	
}

//cout << ans << endl;