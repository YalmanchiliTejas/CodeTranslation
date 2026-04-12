


#include "bits/stdc++.h"

//#include <unordered_map>

//#include <iostream>//POJ
//#include <vector>
//#include <string>
//#include <iomanip>
//#include <math.h>
//#include <algorithm>
//#include <cstring>
using namespace std;
#define setc cin.tie(0);ios::sync_with_stdio(0)
#define repi(i,a,b) for(int i=(a), i##_len=(b); i<i##_len; ++i)
#define rep(i,n) repi(i,0,n)
#define repi_(i,a,b) for(int i=(a), i##_len=(b); i<=i##_len; ++i)
#define rep_(i,n) repi_(i,0,n)
#define repir(i,a,b) for(int i=(a)-1, i##_first=(b); i>=i##_first; --i)
#define repr(i,n) repir(i,n,0)
#define repir_(i,a,b) for(int i=(a), i##_first=(b); i>=i##_first; --i)
#define repr_(i,n) repir_(i,n,0)
#define all(x) (x).begin(),(x).end()
#define vsort(v) sort((v).begin(), (v).end())
#define gsort(v) tsort(v); reverse((v).begin(), (v).end())
#define vrev(v) reverse((v).begin(), (v).end())
//template<typename T> T vpop(vector<T> *v) {
//	T res = v->back();
//	v->pop_back();
//	return res;
//}
//char vpop(string *v) {
//	char res = v->back();
//	v->pop_back();
//	return res;
//}
#define siz(v) ((int)(v).size())
#define ers(v, n) (v).erase((v).begin() + n)
#define cnt(v, n) count(all(v), n)
#define vmin(v) *min_element(v.begin(), v.end())
#define vmax(v) *max_element(v.begin(), v.end())
#define contain(q) !q.empty()
#define cont(q) !q.empty()
//#define qpop(q, a, b) a=q.back().first;b=q.back().second;q.pop()
//#define pqpop(p, a, b) a=q.top().first;b=q.top().second;q.pop()
#define el "\n"
#define sp " "
#define co(x) cout<<(x)<<el
#define coc(c, a, b) if(c)co((a));else co((b))
#define cosp(x) cout<<(x)<<' '
#define YES(c) coc(c,"YES", "NO")
#define Yes(c) coc(c,"Yes", "No")
#define yes(c) coc(c,"yes", "no")
#define POSSIBLE(c) coc(c, "POSSIBLE", "IMPOSSIBLE")
#define Possible(c) coc(c, "Possible", "Impossible")
#define possible(c) coc(c, "possible", "impossible")
#define inf INT_MAX
#define wildcard(T) numeric_limits<T>::min()

#define pb push_back
#define pq priority_queue
#define np next_permutation

#ifdef tqktmp_2
#define gc() getchar(); getchar()
#else
#define gc() 1
#endif
const unsigned int bf0 = (1 << 0);
const unsigned int bf1 = (1 << 1);
const unsigned int bf2 = (1 << 2);
const unsigned int bf3 = (1 << 3);
const unsigned int bf4 = (1 << 4);
const unsigned int bf5 = (1 << 5);
const unsigned int bf6 = (1 << 6);
const unsigned int bf7 = (1 << 7);

typedef long long lint;
typedef vector<int> ivec; typedef vector<string> svec;
typedef vector<lint> lvec;
typedef vector<vector<int>> ivvec;
typedef pair<int, int> P;

const int
dx8[8] = { 0,1,1,1,0,-1,-1,-1 },
dy8[8] = { 1,1,0,-1,-1,-1,0,1 },
dx4[4] = { 0,1,0,-1 },
dy4[4] = { 1,0,-1,0 };

template<class T>inline bool maxi(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>inline bool mini(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

int main(){
	setc;

	lint a,b;cin>>a>>b;
	svec mp;
	string in;
	int ad=0, bd=0;
	rep(i, a){
		cin>>in;
		if(in.find('#')!=string::npos)mp.pb(in);
		else ++ad;
	}

	bool f;
	rep(j, b){
		f=0;
		rep(i, siz(mp)){
			if(mp[i][j-bd]=='#')f=1;
		}
		if (!f){
			
			rep(i, siz(mp)){
				ers(mp[i], (j-bd));
			}
			++bd;
		}
	}


	rep(i, a-ad){
		co(mp[i]);
	}
	gc();
}