#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#define rep(i,l,n) for(lint i=l;i<n;i++)
#define rer(i,l,n) for(lint i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef vector<int> vi;
typedef vector<lint> vli;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main(){
	int n;
	while (1){
		cin >> n;
		if (n == 0) break;
		int ans = 1;
		int d[7] = { 0, 1, 2, 3, 4, 5, 6 };
		string s;
		rep(i, 0, n){
			cin >> s;
			if (s == "North"){
				swap(d[1], d[2]);
				swap(d[2], d[6]);
				swap(d[6], d[5]);
			}
			else if (s == "East"){
				swap(d[1], d[4]);
				swap(d[4], d[6]);
				swap(d[6], d[3]);
			}
			else if (s == "West"){
				swap(d[1], d[3]);
				swap(d[3], d[6]);
				swap(d[6], d[4]);
			}
			else if (s == "South"){
				swap(d[1], d[5]);
				swap(d[5], d[6]);
				swap(d[6], d[2]);
			}
			else if (s == "Right"){
				swap(d[2], d[3]);
				swap(d[3], d[5]);
				swap(d[5], d[4]);
			}
			else{
				swap(d[2], d[4]);
				swap(d[4], d[5]);
				swap(d[5], d[3]);
			}
			ans += d[1];
		}
		o(ans);
	}
}