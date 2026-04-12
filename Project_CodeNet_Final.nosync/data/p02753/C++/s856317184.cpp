#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define vll vector<ll>

using namespace std;

const ll N = 3e5+100;
const ll MOD = 1e9+7;

int main()
{
	string s;
	cin >> s;
	for(int i =0;i<3;i++){
		for(int j= 0;j<3;j++){
			if(s[i] != s[j]) return cout << "Yes\n",0;
		}
	}

	cout << "No\n";
	
	return 0;
}