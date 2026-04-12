#include<bits/stdc++.h> 

using namespace std;

typedef short sho;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
typedef string str; 
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll; 
typedef pair<ld,ld> pld;
 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<pld> vpd;

#define STDIO
#define mp make_pair 
#define FF first
#define SS second
#define sz(x) (int)x.size()
#define begin(x) (x).begin() 
#define end(x) (x).end()
#define rbegin(x) (x).rbegin()
#define rend(x) (x).rend()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front 
#define pb push_back
#define pp push
#define lb lower_bound 
#define ub upper_bound

inline void checkmin(int &x, int y){x = min(x, y);}
inline void checkmax(int &x, int y){x = max(x, y);}

string s;

int main() {
	#ifndef STDIO
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /* start code */
    cin>>s;
    if(s == "AAA" || s == "BBB") {
    	cout<<"No"<<endl;
	}else {
		cout<<"Yes"<<endl;
	}
    /* end code */
	return 0;
}