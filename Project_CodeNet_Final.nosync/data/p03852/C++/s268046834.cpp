#include<bits/stdc++.h>
const long long INF = LLONG_MAX / 2;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i,r,n) for(int i = (ll)(r); i < (ll)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ll long long int
#define ALL(x) (x).begin(),(x).end()
using namespace std;
ll ans = 0, sum = 0, n, k, counter = 0, w, h;
string s;
vector<ll> v;
vector < pair<ll, ll > > vp;
vector<vector<ll> > vv(50, vector<ll>(50, INF));
vector<string> vs;

int main() {
	char a;
	cin >> a;
	if (a == 'a'|| a == 'i' || a == 'u' || a == 'e' || a == 'o') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}