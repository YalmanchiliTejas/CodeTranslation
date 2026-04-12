#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cctype>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,b,e) for(int i = (b); i <= (e); i++)
#define INF (1001001001)
#define EPS (1e-15)

#define pr(x) do{cerr << (#x) << " = " << (x) << endl;}while(0)
#define pri(x,i) do{cerr << (#x) << "[" << i << "] = " << (x[i]) << endl;}while(0)
#define pra(x) do{rep(__i,(x).size()) pri(x,__i);}while(0)
#define pran(x,n) do{rep(__i,n) pri(x,__i);}while(0)
#define pral(x) do{cerr << (#x) << " =";rep(__i,(x).size()) cerr<<" "<<(x[__i]);cerr<<endl;}while(0)
#define prar(x,b,e) do{repr(__i,b,e) pri(x,__i);}while(0)

typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;

template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool CHMAX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool CHMIN(T &l,const T &r){return l>r?l=r,1:0;}

ll MOD = 1000000007;

function<void(int,int)> tensi_no_3p=[&](int v,int d){
};

int in() {
	int a;
	scanf("%d ", &a);
	return a;
}

int main() {
	int N = in();
	vint A(N);
	rep(i,N) A[i] = in();
	vint B = A;
	sort(B.begin(), B.end());
	int s = B[N / 2 - 1], t = B[N / 2];
	rep(i,N) {
		if (A[i] >= t) cout << s << endl;
		else cout << t << endl;
	}
	return 0;
}
