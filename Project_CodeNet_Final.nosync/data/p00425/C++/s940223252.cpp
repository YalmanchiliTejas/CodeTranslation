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

int dice[10];

int main() {
	int n;
	while(n=in()){
		int i;
		string str;
		dice[0]=1;
		dice[1]=2;
		dice[2]=4;
		dice[3]=5;
		dice[4]=3;
		dice[5]=6;
		int buf;
		int res=1;
		for(i=0;i<n;i++){
			cin>>str;
			if(str=="North"){
				buf=dice[0];
				dice[0]=dice[1];
				dice[1]=dice[5];
				dice[5]=dice[3];
				dice[3]=buf;
			}
			if(str=="East"){
				buf=dice[0];
				dice[0]=dice[2];
				dice[2]=dice[5];
				dice[5]=dice[4];
				dice[4]=buf;
			}
			if(str=="West"){
				buf=dice[0];
				dice[0]=dice[4];
				dice[4]=dice[5];
				dice[5]=dice[2];
				dice[2]=buf;
			}
			if(str=="South"){
				buf=dice[0];
				dice[0]=dice[3];
				dice[3]=dice[5];
				dice[5]=dice[1];
				dice[1]=buf;
			}
			if(str=="Right"){
				buf=dice[1];
				dice[1]=dice[4];
				dice[4]=dice[3];
				dice[3]=dice[2];
				dice[2]=buf;
			}
			if(str=="Left"){
				buf=dice[1];
				dice[1]=dice[2];
				dice[2]=dice[3];
				dice[3]=dice[4];
				dice[4]=buf;
			}
			res+=dice[0];
		}
		cout<<res<<endl;
	}
	return 0;
}