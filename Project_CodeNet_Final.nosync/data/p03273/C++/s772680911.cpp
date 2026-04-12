#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int h,w; cin >> h >> w;
	string s[h];
	vector<bool>row(h,1),col(w,1);
	for(int i=0; i<h; i++){
		cin >> s[i];
		for(int j=0; j<w; j++){
			if(s[i][j]=='#'){
				row[i]=0;
				col[j]=0;
			}
		}
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(!row[i]&&!col[j])cout << s[i][j];
		}
		if(!row[i])cout << endl;
	}
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
