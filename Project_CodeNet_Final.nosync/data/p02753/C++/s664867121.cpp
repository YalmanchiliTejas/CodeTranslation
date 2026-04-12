#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int,int>
#define ll long long
#define rep(i,a,b) for(int i=int(a); i<=int(b);i++)
#define repv(vec,v) for(v=(vec).begin(); v!=(vec).end();v++)
#define sz(vec) (int)(vec).size()
#define PB push_back
#define F first()
#define S second()


int main(){
	string s;
	cin >> s;
	if(s[0] == s[1] && s[1] == s[2])
		cout << "No";
	else
		cout << "Yes";
	
	return 0;
}
