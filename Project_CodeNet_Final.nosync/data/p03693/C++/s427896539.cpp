#include<bits/stdc++.h>                
using namespace std;
#define REP(i,n) for(auto i = 0; i < (n); ++i)
#define REP1(i,n) for(auto i = 0; i <= (n); ++i)
#define REPO(i,o,n) for(auto i = (o); i < (n); ++i)
#define REPR(i,n) for(auto i = (n)-1; i >= 0; --i)
#define REPI(itr,v) for(auto itr=v.begin(); itr != v.end(); ++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin(); itr != v.rend(); ++itr)
#define ALL(v) v.begin(), v.end()
#define SV(n,v) {int tmp;for(int i=0;i<n;++i){scanf("%d",&tmp);v.push_back(tmp);}}
#define push_back pb;
#define push_front pf; 
#define make_pair mp;
#define first fi;
#define second se;
typedef long long ll;

int N, tmp;
int main(void){
	REP(i,3){
		cin >> tmp;
		N = N * 10 + tmp;
	}
	if(N % 4) cout << "NO" << endl;
	else cout << "YES" << endl;
}
