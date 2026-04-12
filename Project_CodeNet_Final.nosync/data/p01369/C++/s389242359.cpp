#include <bits/stdc++.h>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

char a[]={'y','u','i','o','p','h','j','k','l','n','m'};

inline bool isright(char in){
	rep(i,11) if(in==a[i]) return true;
	return false;
}

int solve(string in){
	int n=in.size();
	bool flag=isright(in[0]);
	int ans=0;
	for(int i=1;i<n;++i){
		bool next=isright(in[i]);
		if(flag^next)
			ans++;
		flag=next;
	}
	return ans;
}

int main(void){
	string in;
	while(cin >> in){
		if(in=="#")
			break;
		int ans=solve(in);
		cout << ans << endl;
	}
	return 0;
}