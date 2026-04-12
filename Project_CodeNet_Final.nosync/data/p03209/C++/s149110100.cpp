


#include "bits/stdc++.h"

#include <unordered_set>
#include <unordered_map>

//#include <iostream>//POJ
//#include <vector>
//#include <string>
//#include <iomanip>
//#include <math.h>
//#include <algorithm>
//#include <cstring>
using namespace std;
#define l0 (lint)0
#define setc cin.tie(0);cout.tie(0);ios::sync_with_stdio(0)
#define dd(n) cout<<fixed<<setprecision(n)
//#define repi(i,a,b) for(int i=(a), i##_len=(b); i<i##_len; ++i)
#define repi(i,a,b) for(int i=(a);i<b;++i)
#define rep(i,n) repi(i,0,n)
#define repi_(i,a,b) for(int i=(a), i##_len=(b); i<=i##_len; ++i)
#define rep_(i,n) repi_(i,0,n)
#define repir(i,a,b) for(int i=(a)-1, i##_first=(b); i>=i##_first; --i)
#define repr(i,n) repir(i,n,0)
#define repir_(i,a,b) for(int i=(a), i##_first=(b); i>=i##_first; --i)
#define repr_(i,n) repir_(i,n,0)
#define prep(i,n) for(int i=0;i*i<n;++i)
#define prepi(i,a,b) for(int i=a;i*i<=b;++i)
#define all(x) (x).begin(),(x).end()
#define vsort(v) sort((v).begin(), (v).end())
#define vcsort(v,c) sort((v).begin(),(v).end(),c)
#define vrev(v) reverse((v).begin(), (v).end())
#define fnd(v,x) ((v).find(x)!=string::npos)
#define mod(a,b) (a<0?a%b+abs(b):a%b)
#define cl(a,b) ((a+b-1)/b)

//temlyate<typename T> T vpop(vector<T> *v) {
//	T d = v->back();
//	v->pop_back();
//	return d;
//}
//char vpop(string *v) {
//	char d = v->back();
//	v->pop_back();
//	return d;
//}
#define siz(v) ((int)(v).size())
#define ers(v, n) (v).erase((v).begin() + n)
#define vmin(v) *min_element(v.begin(), v.end())
#define vmax(v) *max_element(v.begin(), v.end())
#define contain(q) !q.empty()
#define cont(q) !q.empty()
//#define qpop(q, a, b) a=q.back().first;b=q.back().second;q.pop()
//#define pqpop(p, a, b) a=q.top().first;b=q.top().second;q.pop()
#define el "\n"
#define sp " "
#define pi 3.14159265358979
#define co(x) cout<<x<<el
#define coc(c, a, b) co(((c)?a:b))
#define cim(x) {cin>>x;--x;}
#define cim2(a,b) {cin>>a>>b;--a;--b;}
#define cosp(x) cout<<(x)<<' '
#define YES(c) coc(c,"YES", "NO")
#define Yes(c) coc(c,"Yes", "No")
#define yes(c) coc(c,"yes", "no")
#define POSSIBLE(c) coc(c, "POSSIBLE", "IMPOSSIBLE")
#define Possible(c) coc(c, "Possible", "Impossible")
#define possible(c) coc(c, "possible", "impossible")
#define inf INT_MAX
#define linf INT64_MAX*0.99
#define wildcard(T) numeric_limits<T>::min()
#define noway() {co(-1);gc();return 0;}

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

//#define lint long long
typedef long long lint;
typedef vector<int> IV; typedef vector<string> SV;
typedef vector<lint> LIV;
typedef vector<vector<int>> IVV;
typedef pair<int,int> P; typedef pair<lint,lint> LP;
typedef vector<P> PV; typedef vector<LP> LPV;

const int
dx8[8] ={0,1,1,1,0,-1,-1,-1},
dy8[8] ={1,1,0,-1,-1,-1,0,1},
dx9[9] ={0,1,1,1,0,0,-1,-1,-1},
dy9[9] ={1,1,0,-1,0,-1,-1,0,1},
dx6[2][6]={{0,1,0,-1,-1,-1},{1,1,1,0,-1,0}},
dy6[6]={-1,0,1,1,0,-1},
dx5[5] ={0,1,0,0,-1},
dy5[5] ={1,0,0,-1,0},
dx4[4] ={0,1,0,-1},
dy4[4] ={1,0,-1,0};
//temlyate<class... A> void cim_(A... args) {
//	for (A *i : initializer_list<A*>{ args... }) {
//		cin>>*i;--*i;
//	}
//	return;
//}
lint input[5];

template<class T>inline bool maxi(T &a,const T &b){ if(a < b){ a = b; return 1; } return 0; }
template<class T>inline bool mini(T &a,const T &b){ if(b < a){ a = b; return 1; } return 0; }

#define MAX_N 200020
const int md = 1e9+7;

struct AB{ lint a,b; };//a,b
struct ABC{ lint a,b,c; };//a,b,c
struct C{ lint x,y; };//coords
struct SEC{ lint l,r; };//section

char joi[4]="JOI";

lint rec(lint n,lint x){
	if(n==1)return 1;
	if(x<n-1)return 0;
	if(x<((2LL<<n)-3)/2)return rec(n-1,x-1);
	if(x>((2LL<<n)-3)/2)return (1LL<<(n-1))-1+1+rec(n-1,x-(1LL<<n)-2+3);
	return (1LL<<(n-1));
}

int main(){
	setc;

	lint n,x;cin>>n>>x;
	co(rec(n+1,x-1));
	gc();
}