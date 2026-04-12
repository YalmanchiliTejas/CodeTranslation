#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
//#include <utility>
#include <set>
#include <iostream>
//#include <memory>
#include <string>
#include <vector>
#include <algorithm>
//#include <functional>
#include <sstream>
//#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
//#include <cctype>
#include <cstring>
//#include <ctime>
#include <iterator>
#include <bitset>
//#include <numeric>
//#include <list>
//#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#else

#endif

using namespace std;


namespace{
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}


#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8
static const int INF=1<<24;

void mainmain(){
	int N,M,K,L;
	while(scanf("%d %d %d %d",&N,&M,&K,&L),N||M||K||L){
		vector<pair<int,string>> in1(N);
		rep(i,N){
			cin>>in1[i].S;
			scanf("%d",&in1[i].F);
			in1[i].F*=-1;
		}
		set<string> se;
		string tmps;
		rep(i,M){
			cin>>tmps;
			se.insert(tmps);
		}
		sort(ALL(in1));
		priority_queue<pii> pq1;
		priority_queue<pii> pq2;
		priority_queue<pii> pq3;
		// rep(i,in1.size()){
			// cout<<i<<" "<<-in1[i].F<<" "<<in1[i].S<<endl;
		// }
		// cout<<endl;
		rep(i,in1.size()){
			if(i<K){
				if(se.find(in1[i].S)!=se.end()){
					// cout<<i<<" "<<2<<endl;
					pq2.push(mkp(in1[i].F,-i));
				}
				else{
					// cout<<i<<" "<<1<<endl;
					pq1.push(mkp(in1[i].F,-i));
				}
			}
			else{
				if(se.find(in1[i].S)!=se.end()){
					// cout<<i<<" "<<3<<endl;
					pq3.push(mkp(-in1[i].F,-i));
				}
			}
		}
		while(1){
			if(pq3.empty()){
				break;
			}
			if(pq1.empty()){
				break;
			}
			pii top3=pq3.top();
			pii top1=pq1.top();
			pii top2;
			bool f2=!pq2.empty();
			// if(f2) cout<<"hoge"<<endl;
			if(f2) top2=pq2.top();
			// cout<<"top1 "<<-top1.F<<" "<<in1[-top1.S].S<<endl;
			// if(f2) cout<<"top2 "<<-top2.F<<" "<<in1[-top2.S].S<<endl;
			// cout<<"top3 "<< top3.F<<" "<<in1[-top3.S].S<<endl;
			pq3.pop();
			L-=-top1.F-top3.F;
			top3.F=-top1.F;
			if(in1[-top3.S].S>in1[-top1.S].S){
				top3.F++;
				L--;
			}
			// cout<<"L "<<L<<endl;
			if(L<0){
				break;
			}
			top3.F*=-1;
			if(!f2||top2.F<top1.F||(top2.F==top1.F&&in1[-top2.S].S<in1[-top1.S].S)){
				top1.F*=-1;
				pq1.pop();
				pq2.push(top3);
			}
			else{
				top2.F*=-1;
				pq3.push(top2);
				pq2.pop();
				pq2.push(top3);
			}
		}
		cout<<pq2.size()<<endl;
	}
}



}
main() try{
    mainmain();
}
catch(...){
}