#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define MAX 1e9
#define MIN -1e9
#define MOD 1000000007
#define println(x) cout << "[" << #x << ":" << x << "]\n"; 
#define print(x) cout << "[" << #x << ":" << x << "] "; 

int main(){
	ios::sync_with_stdio(0); 
    cin.tie(0); 
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int x; cin >> x;
	if(x >= 30)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}