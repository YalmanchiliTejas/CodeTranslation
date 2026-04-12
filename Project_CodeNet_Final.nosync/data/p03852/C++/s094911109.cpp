#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	char a; cin >> a;
	if(a=='a'|| a=='i'|| a=='u'|| a=='e'|| a=='o') cout << "vowel" << endl;
	else cout << "consonant" << endl;
}