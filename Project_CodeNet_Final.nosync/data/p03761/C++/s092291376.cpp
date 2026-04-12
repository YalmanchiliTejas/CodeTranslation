#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define loop(i,x,y) for(ll i=x;i<y;i++)
#define pb push_back
#define S second
#define F first



void solve(){
	
	int n;
	cin >> n;

	string s;

	cin >> s;

	vector <char> list;

	map <char, int> check;

	for(char c: s)
		check[c]++;

	
	for(int i = 0; i < n-1 ; i++){

		cin >> s;

		map <char, int> rest;

		for(char c: s)
			rest[c]++;

		for(auto it: check){

			char test = it.first;

			if(rest.find(test) != rest.end())
				check[test] = min(rest[test], check[test]);
			else
				check[test] = 0;

		}

	}

	string ans = "";
	for(auto it: check){

		char c = it.first;
		int val = it.second;

		for(int i = 0; i < val; i++)
			ans += c;

	}

	cout << ans << endl;

}
	
 
 
int main(){
	    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	solve();
	 
	return 0;
 
}

	 
