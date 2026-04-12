#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int score[100000];

int main() {
	int i,n;
	for(i=1;scanf("%d,%d",&n,score+i),n;i++){
	}
	n=i-1;
	for(;cin>>i;){
		int res=0;
		int k;
		for(k=30;k>score[i];k--){
			int j;
			for(j=1;j<=n;j++){
				if(score[j]==k){
					res++;
					break;
				}
			}
		}
		cout<<res+1<<endl;
	}
	return 0;
}