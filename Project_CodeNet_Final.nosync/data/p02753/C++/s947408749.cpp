#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
string s;
int ac, bc;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> s;
	for(auto u : s){
		if(u == 'A') ac++;
		else bc++;
	}

	if(!bc || !ac){
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;


	cout.flush();
	return 0;
}