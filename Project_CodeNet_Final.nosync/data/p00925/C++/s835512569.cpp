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

string s;
size_t cur=0;

int digit(){
	int d=(s[cur++]-'0');
	return d;
}

int number(){
	int res=digit();
	int n=s.size();
	while(cur<n&&isdigit(s[cur])){
		res=10*res+digit();
	}
	return res;
}

int lr(){
	int res=number();
	int n=s.size();
	while(cur<n){
		char op=s[cur++];
		int arg=number();
		if(op=='+')
			res+=arg;
		else
			res*=arg;
	}
	return res;
}

int add(){
	int res=number();
	int n=s.size();
	while(cur<n&&s[cur]=='*'){
		cur++;
		int arg=number();
		res*=arg;
	}
	return res;
}

int mul(){
	int res=add();
	int n=s.size();
	while(cur<n&&s[cur]=='+'){
		cur++;
		int arg=add();
		res+=arg;
	}
	return res;
}
int main(void){
	cin >> s;
	int in;
	cin >> in;

	cur=0;
	bool res=(lr()==in);
	cur=0;
	bool res2=(mul()==in);

	if(res&res2)
		puts("U");
	else if(res)
		puts("L");
	else if(res2)
		puts("M");
	else
		puts("I");
	return 0;
}