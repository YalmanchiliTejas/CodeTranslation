#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <string.h>
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (int)(n); i++)
#define reps(i,x) for(ll i=1;i<=(int)(x);i++)
#define rrep(i,x) for(ll i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(ll i=((int)(x) - 1 * 100);i>0;i--)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define vll vector<ll>
#define vi vector<int>
#define mp make_pair
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
using namespace std;
ll n;
int main() {
	cin >> n;
	string s;
	map<char, int> mp3;
	map<char, int> mp1;
	rep(i, n) {
		map<char, int> mp2;
		cin >> s;
		rep(j, s.size()) {
			mp2[s[j]]++;
		}
		for (auto kv : mp2) {
			if (!i) {
				mp3[kv.first] = mp2[kv.first];
			}
		
			else if (mp1[kv.first] > kv.second) {
				mp3[kv.first] = kv.second;
			}
			else  {
				mp3[kv.first] = mp1[kv.first];
			}
		}
		mp1.erase(mp1.begin(), mp1.end());
		for (auto kv : mp3) mp1[kv.first] = kv.second;
		mp3.erase(mp3.begin(), mp3.end());
	}
	for (auto kv : mp1) {
		rep(i, kv.second) {
			cout << kv.first;
		}
	}
	cout << endl;
	return 0;
}