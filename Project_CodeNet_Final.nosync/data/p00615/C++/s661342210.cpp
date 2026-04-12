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

int cars[20010];

int main() {
	int a,b;
	while(a=in(),b=in(),a||b){
		a+=b;
		int i;
		for(i=0;i<a;i++){
			cin>>cars[i];
		}
		cars[a]=0;
		sort(cars,cars+a+1);
		int mx=0;
		for(i=0;i<a;i++){
			chmax(mx,cars[i+1]-cars[i]);
		}
		cout<<mx<<endl;
	}
	return 0;
}