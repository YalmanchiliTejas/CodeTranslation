#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()
 
using namespace std;
using ll = long long;
 
struct edge { int to, cost; };
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
 
const int INF = 1e9;
//const ll INF = 1e18;
const double EPS = 1e-10;
const int MOD = 1e9+7;
const double PI = acos(-1.0);

const int mx4[] = {0,1,0,-1};
const int my4[] = {1,0,-1,0};
const int mx8[] = {0,1,1,1,0,-1,-1,-1};
const int my8[] = {1,1,0,-1,-1,-1,0,1};

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;
	for(int i = 0; i < s.size(); i++){
		if(s[k-1] == s[i]) cout << s[i];
		else cout << '*';
	}
	cout << endl;
	return 0;
}