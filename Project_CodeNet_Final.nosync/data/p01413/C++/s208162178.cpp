#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

#define int long long
#define reps(i,f,n) for(int i=f;i<n;i++)
#define rep(i,n) reps(i,0,n)
#define f first
#define s second

typedef pair<int,int> pii;

const int N = 8;
const int M = 8;
const int W = 21111;
const int T = 21111;
const int INF = 1e16;
int n,m,w,t;

map<string, int> dict;
pii  item[M];

pii pos[N];
int shop[N][M];


int memo[(1<<N)][N];


void memoInit(){
	for(int i=0;i<(1<<N);i++)rep(j,N)memo[i][j]=-1;
}
int Root(int state, int num){

	if(state==0)return 0;

	if(memo[state][num]!=-1)return memo[state][num];
	if(state==(1<<num))return abs(pos[num].f) + abs(pos[num].s);
	state &= ~(1<<num);

	int ans = INF;
	for(int i=0;i<n;i++){
		if((state & (1<<i)) > 0){
			int dist = abs(pos[num].f - pos[i].f) + abs(pos[num].s - pos[i].s);
			ans = min(ans, Root(state, i) + dist);
		}
	}

	return memo[state][num] = ans ;
}

int GetTime(int state){


	int ans = INF;
	for(int i=0;i<n;i++){

		if( (state&(1<<i))>0 ) {
			int r  = Root(state,i);
			ans = min(ans, r + abs(pos[i].f) + abs(pos[i].s));
		}
	}
	return ans;
}

int GetValue(int state){
	
	
	int has[M] = {0};
	rep(i,M)has[i] = -1;

	rep(i,n){
		if((state&(1<<i)) > 0){
			rep(j,m){
				if(shop[i][j]!=-1){
					has[j] = max(has[j], shop[i][j]);
				}
			}
		}
	}


	int dp[W] = { 0};

	int ans = 0;
	for(int i=0;i<w+1;i++){

		rep(j,7){
			if(has[j]==-1)continue;
			int wi = item[j].f;
			int vi = has[j];
			dp[i+wi] = max(dp[i+wi], dp[i] + vi);
		}
		ans = max(ans, dp[i]);
	}

	return ans;
}

vector<pii> GetCand(){

	vector<pii> cand;
	for(int i=0;i<(1<<n);i++){
		cand.push_back(pii(GetTime(i), GetValue(i)));
	}
	return cand;
}

int dp[T] = {0};

int solve(){

	vector<pii> cand = GetCand();

	for(int i=0;i<cand.size();i++){
		//printf("*** %lld %lld\n",cand[i].f, cand[i].s);
	}
	rep(i,T)dp[i]=0;


	int ans = 0;
	rep(i,t+1){
		rep(j,cand.size()){
			pii c = cand[j];
			if(i+c.f >= T){
				continue;
			}

			dp[i + c.f] = max(dp[i+c.f], dp[i] + c.s);
			ans = max(ans, dp[i]);
		}
	}

	return ans;
}

signed main(){
	memoInit();
	cin>>n>>m>>w>>t;

	rep(i,m){
		string s;
		int a,b;
		cin>>s>>a>>b;
		dict[s] = i;
		item[i] = pii(a,b);
	}

	rep(i,N)rep(j,M)shop[i][j] = -1;

	rep(i,n){
		int a,x,y;
		cin>>a>>x>>y;
		pos[i] = pii(x,y);

		rep(j,M)shop[i][j]=-1;
		rep(j,a){
			string s;
			int p;
			cin>>s>>p;
			int num = dict[s];
			shop[i][num] = max(shop[i][num], max(0ll, item[num].s-p));
		}
	}

	cout<<solve()<<endl;
}