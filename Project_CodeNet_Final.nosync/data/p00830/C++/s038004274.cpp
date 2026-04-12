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

int nexts=1;
map<string,int> dir[10010];
bool page[10010];

void insert(void){
	int cur=0;
	int index=0;
	int prev=-1;
	string in;
	cin >> in;
	int n=in.size();
	while(index+1<n){
		int num=1;
		while(index+num<n&&in[index+num]!='/')num++;
		string nx=in.substr(index+1,num-1);
		if(dir[cur].find(nx)==dir[cur].end())
			dir[cur][nx]=nexts++;
		dir[cur]["."]=cur;
		if(prev!=-1) dir[cur][".."]=prev;
		prev=cur;
		cur=dir[cur][nx];
		index+=num;
	}
	page[cur]=true;
}

int find(){
	int cur=0;
	int index=0;
	string in;
	cin >> in;
	int n=in.size();
	while(index+1<n){
		int num=1;
		while(index+num<n&&in[index+num]!='/')num++;
		string nx=in.substr(index+1,num-1);
		if(dir[cur].find(nx)==dir[cur].end())
			return -1;
		cur=dir[cur][nx];
		index+=num;
	}
	if(in[n-1]=='/'||in[n-1]=='.'||!page[cur]){
		if(dir[cur].find("index.html")==dir[cur].end())
			return -1;
		else{
			cur=dir[cur]["index.html"];
			if(page[cur])
				return cur;
			else
				return -1;
		}
	}else
		return cur;
}


int main(void){
	int n,m;
	while(cin >> n >> m){
		if(n==0&&m==0)
			break;
		rep(i,10010) dir[i].clear(),page[i]=false;
		nexts=1;
		rep(i,n) insert();
		rep(i,m){
			int a=find();
			int b=find();
			if(a==-1||b==-1)
				cout << "not found" << endl;
			else if(a==b)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
	}
	return 0;
}

// '.' or '..' '/' is directory therefore check index.html
// otherwise if this is page check page otherwise this is directory check directory/index.html and is directory/index.html page?