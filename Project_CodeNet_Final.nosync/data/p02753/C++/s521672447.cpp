#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	set<char> df;
	for(int i = 0; i < s.length(); i++)df.insert(s[i]);
	if(df.size() == 2)
		cout << "Yes\n";
	else cout << "No\n";

}