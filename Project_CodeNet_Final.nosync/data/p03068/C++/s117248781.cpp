#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 100005
 
#define PI 3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007

map<string, int> m;




int main()
{
	FAST;
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll m;
	cin >> m;
	for(ll i = 0; i < s.size(); i ++){
		if(s[i] != s[m-1]){
			s[i] = '*';
		}
	}
	cout << s;
	return 0;
}