#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int N;
vector<int> A;

int main()
{
	scanf("%d",&N);
	A.assign(N,0);
	FOR(i,0,N){
		scanf("%d",&A [i]);
	}

	deque<int> ans;
	bool rev = false;
	FOR(i,0,N){
		if(rev == false){
			ans.push_back(A [i]);
		}
		else{
			ans.push_front(A [i]);
		}
		rev = !rev;
	}
	if(rev){
		reverse(ans.begin(),ans.end());
	}
	FOR(i,0,N){
		printf("%d%s",ans [i],i + 1 == N ? "\n" : " ");
	}

	return 0;
}
