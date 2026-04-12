/***********************************************************
	When you are inspired by passion 
	and you want to live for the current moment

	When your every thought and action
	has the power to become the story of your future

	When difficulties stand to demolish your Glory
	Just remember that Life is a 'Golden adverse Story'

	Withstand it to acheive your passion and dreams
	more amazingly more easily.

	Why then? When writing the story of your Life
	You want to Let someone else hold your pen

					huzaifa242©

***********************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define MAX 100005
#define x first 
#define y second

int seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l=0,int r=INT_MAX)
{return uniform_int_distribution<int>(l,r)(rng);}

template <typename T,typename G>
ostream& operator << (ostream& out, const pair<T,G> &a) 
{return out<<"( "<<a.x<<", "<<a.y<<")";}

template <typename T>
ostream& operator << (ostream& out, const vector<T> &a) 
{out<<"[ ";for(const auto &i:a)out<<i<<", ";return out<<"]"<<endl;}

template <typename T>
ostream& operator << (ostream& out, const set<T> &a) 
{out<<"{ ";for(const auto &i:a)out<<i<<", ";return out<<"}"<<endl;}

template <typename T,typename G>
ostream& operator << (ostream& out, const map<T,G> &a) 
{out<<"< ";for(const auto &i:a)out<<i<<", ";return out<<">"<<endl;}

template<typename T, size_t N>
typename enable_if<!is_same<typename remove_cv<T>::type, char>::value,
ostream&>::type operator<<(ostream& out, T(&a)[N])
{out<<"[ ";for(size_t i=0;i<N;++i)out<<a[i]<<", ";out <<"]"<<endl;return out;}

void debug_out(){cerr<<endl;} 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{cerr<<(H)<<" ";debug_out(T...);}
 
#ifdef LOCAL
#define debug(...) cerr<<"#"<<#__VA_ARGS__<<":\n",debug_out(__VA_ARGS__)
#else
#define debug(...) 24
#endif

int dp[MAX][2][4],k;
vector<int> digi;

int call(int id, int ls, int sm){
	if(sm> k) 
		return 0;
	if(id==digi.size()){
		if(sm==k)
			return 1;
		else
			return 0;
	}
	if(dp[id][ls][sm]!=-1)
		return dp[id][ls][sm];
	int dans=0;
	if(!ls){
		for(int i=0;i<=digi[id];i++)
			dans+=call(id+1,ls|(i<digi[id]),sm+(i>0));
	}else{
		for(int i=0;i<=9;i++)
			dans+=call(id+1,ls,sm+(i>0));	
	}
	return dp[id][ls][sm]=dans;
}

int solve(string &s){
	digi.clear();
	memset(dp,-1,sizeof(dp));	
	for(auto &c:s){
		digi.push_back(c-'0');
	}
	return call(0,0,0);
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	string s;
	int i;
	cin>>s>>k;
	cout<<solve(s);
	return 0;
}
