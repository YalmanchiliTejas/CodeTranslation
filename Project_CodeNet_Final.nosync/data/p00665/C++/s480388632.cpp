#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
using namespace std;


namespace{
typedef long long ll;
typedef pair<int,int> pii;

#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
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
		rep(i,in1.size()){
			if(i<K){
				if(se.find(in1[i].S)!=se.end()){
					pq2.push(mkp(in1[i].F,-i));
				}
				else{
					pq1.push(mkp(in1[i].F,-i));
				}
			}
			else{
				if(se.find(in1[i].S)!=se.end()){
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
			if(f2) top2=pq2.top();
			pq3.pop();
			L-=-top1.F-top3.F;
			top3.F=-top1.F;
			if(in1[-top3.S].S>in1[-top1.S].S){
				top3.F++;
				L--;
			}
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