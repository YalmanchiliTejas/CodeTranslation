#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
#define ALL(x) x.begin(),x.end()
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int N,M;
bool edge [9] [9];

int main()
{
	scanf("%d%d",&N,&M);
	FOR(i,0,M){
		int a,b;
		scanf("%d%d",&a,&b);
		edge [a] [b] = edge [b] [a] = true;
	}

	vector<int> v(N);
	FOR(i,0,N){
		v [i] = i + 1;
	}

	int ans = 0;
	do{
		bool ok = true;
		FOR(i,0,N - 1){
			ok &= edge [v [i]] [v [i + 1]];
		}
		if(ok && v.front() == 1){
			ans++;
		}
	}while(next_permutation(ALL(v)));

	printf("%d\n",ans);

	return 0;
}
