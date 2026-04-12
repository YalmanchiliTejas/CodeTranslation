#include<bits/stdc++.h>
using namespace std;

#define INF 1000000007
#define ll long long
#define F first
#define S second
#define pii pair<ll int,ll int>
#define pb push_back
#define ppb pop_back
#define vi vector<ll int>


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin >> t;
	while(t--){
		string str;
		cin >> str;
		if(str[0] == str[1] && str[0] == str[2]) cout << "No";
		else cout << "Yes";
	}
	return 0;
}
