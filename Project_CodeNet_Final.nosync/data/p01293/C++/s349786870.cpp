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

char start;
char trump;
string card[4][13];

int suit(char arg){
	if(trump==arg)
		return 2;
	else if(start==arg)
		return 1;
	else
		return 0;
}

int number(char arg){
	switch(arg){
		case 'A':
			return 1;
		case 'T':
			return 10;
		case 'J':
			return 11;
		case 'Q':
			return 12;
		case 'K':
			return 13;
		default:
			return arg-'0';
	}
	return 0;
}

inline int judge(int i,int a,int b){
	int an=number(card[a][i][0]);
	int ac=suit(card[a][i][1]);
	int bn=number(card[b][i][0]);
	int bc=suit(card[b][i][1]);
	if(ac==bc){
		if(an==1)
			return a;
		if(bn==1)
			return b;
		if(an>bn)
			return a;
		else
			return b;
	}else{
		if(ac>bc)
			return a;
		else
			return b;
	}
	return 0;
}

int proceed(int i,int d){
	int res=d;
	string s=card[d][i];
	start=card[d][i][1];
	for(int j=1;j<=3;++j){
		int cur=(d+j)%4;
		res=judge(i,res,cur);
	}
	return res;
}

int main(void){
	while(cin >> trump){
		if(trump=='#')
			break;
		rep(i,4)rep(j,13) cin >> card[i][j];
		int ns=0,ew=0,d=0;
		rep(i,13){
			int res=proceed(i,d);
			if(res&1)
				ew++;
			else
				ns++;
			d=res;
		}
		if(ew>ns)
			cout << "EW" << " " << ew-6 << endl;
		else
			cout << "NS" << " " << ns-6 << endl;
	}
	return 0;
}