#include "bits/stdc++.h"
#include <cmath>
using namespace std;

#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()
#define clr(a,v) memset(a, v, sizeof(a))

#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, l, r) for (int i = (l); i >= (r); i--)
#define reflex ios_base::sync_with_stdio(false)

#define nl '\n'
#define ioi exit(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N= (int)2e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int kx[] = {-1,1,2,2,1,-1,-2,-2};
const int ky[] = {2,2,1,-1,-2,-2,-1,1};

string conv(int a){
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}


string conv(char a){
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}

int conv(string a){
    stringstream geek(a); 
    int x = 0; 
    geek >> x;   
	return x;
}

int main(void) 
{	
	int n; cin>> n;
	string s; cin>> s;
	int k; cin>> k;
	char c = s[k-1];
	int r = s.size();
	rep(i,0,r-1){
		if(s[i] != c)
			s[i] = '*';
	}
	cout<<s;
	return 0;
} 

