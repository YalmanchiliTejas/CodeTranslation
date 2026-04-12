#include <bits/stdc++.h>

using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = int(s); i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<tint>;
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 3005;
const int INF = 1e9;
const ld PI = acos(ld(-1)); 
 
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
 
bool valid(int x, int y, int n, int m){
	return (0<=x && x<n && 0<=y && y<m);
}
 
void NACHO(string name = "", bool file = 0){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(file){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
 
int main(){
    NACHO();
	int n; cin >> n;
	if(n >= 30) cout << "Yes" << endl;
	else cout << "No" << endl;
}
