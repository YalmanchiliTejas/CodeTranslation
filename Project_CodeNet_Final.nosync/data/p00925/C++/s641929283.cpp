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


string S;
size_t cur;

int digit(){
	int res=S[cur++]-'0';
	return res;
}

int  number(){
	int res=digit();
	while(isdigit(S[cur]))
		res=res*10+digit();
	return res;
}

int left(){
	int res=number();
	while(cur<S.size()){
		if(S[cur]=='+'){
			cur++;
			int next=number();
			res+=next;
		}else if(S[cur]=='*'){
			cur++;
			int next=number();
			res*=next;
		}
	}
	return res;
}

int term(){
	int res=number();
	while(cur<S.size()&&S[cur]=='*'){
		if(S[cur]=='*'){
			cur++;
			int next=number();
			res*=next;
		}	
	}
	return res;
}

int exp(){
	int res=term();
	while(cur<S.size()&&S[cur]=='+'){
		if(S[cur]=='+'){
			cur++;
			int next=term();
			res+=next;
		}	
	}
	return res;
}

int main(void){
	cin >> S;
	int  n;
	cin >> n;
	cur=0;
	bool l=(n==left());
	cur=0;
	bool m=(n==exp());
	if(m&l)
		puts("U");
	else if(m)
		puts("M");
	else if(l)
		puts("L");
	else
		puts("I");
	return 0;
}