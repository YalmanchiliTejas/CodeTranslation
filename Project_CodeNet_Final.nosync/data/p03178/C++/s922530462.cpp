// Best practice
 
#include<bits/stdc++.h>
 
#define int         long long
#define pb          push_back
#define pf          emplace_front
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define pii 		pair<int,int>
#define psi 		pair<string,int>
#define vi 			vector<int>
#define vpii  		vector<pii>
#define vvi 		vector<vi>
#define sz(x)	    (int)(x).size()
#define x           first
#define y           second
#define endl        '\n'
#define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD         1000000007
#define hell        998244353
#define prec(n) 	fixed<<setprecision(n)
#define ini(a, i) 	memset(a, i, sizeof(a))
#define output(x)   cout << (x ? "YES" : "NO")<<endl;
using namespace std;
 
#define debug(vec) cout<<(#vec)<<" : [ "; for (auto& i: vec) cout<<i<<" "; cout<< "]" << endl
#define debugp(vec) cout<<(#vec)<<" : [ "; for (auto& i: vec) cout<<"("<<i.x<<","<<i.y<<")"<<" "; cout<< "]" << endl
#define trace(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);cout << endl; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << "[" << *it << ": " << a << "]\t";
    err(++it, args...);
}
 
// const int dx[4] = { -1, 1, 0, 0};
// const int dy[4] = {0, 0, -1, 1};
// int dX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
// int dY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 
 
// Code from Here -------------------------------------------------------------------------------

const int nax = 10000, maxx = 100;
int n, k, dp[nax][maxx][2];
string s;

int count(int ind, int c, int strict){
	if(ind==n){		
		// if(c%k==0)trace(c);
		return (c==0);
	}
	int &ans = dp[ind][c][strict];
	if(ans!=-1)return ans;
	ans=0;
	int st=0, e=9;
 	if(strict)e=s[ind]-'0';
 	for(int i=st; i<=e; i++){
 		if(i==e && strict)(ans += count(ind+1, (c+i)%k, 1))%=MOD;
 		else (ans += count(ind+1, (c+i)%k, 0))%=MOD;
 	}
 	return ans;
}

signed main() {
	tezz
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif

	cin >> s;
	n=s.length();
	cin >> k;
	ini(dp, -1);
	cout << (count(0, 0, 1)-1+MOD)%MOD << endl;
 
	return 0;
}  