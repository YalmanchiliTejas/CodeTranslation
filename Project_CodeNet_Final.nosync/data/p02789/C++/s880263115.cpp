#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define si set<ll>
#define endl "\n"
#define pb(a) push_back(a)
#define x first
#define y second
//g++-9 -std=c++11 -Wall -Wextra -pedantic-errors main.cpp -o main
const ll ms = 1e4 + 5, base = 31, mod = 1e9 + 9;
using namespace std;

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	if (M == N)
		cout << "Yes";
	else
		cout << "No";
	
	cout << endl;
	return 0;
}