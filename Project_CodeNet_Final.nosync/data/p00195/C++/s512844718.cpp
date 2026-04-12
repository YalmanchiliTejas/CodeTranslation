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

int main() {
	int a,b;
	int mx;
	char res;
	while(a=in(),b=in()){
		mx=a+b;
		res='A';
		int i;
		for(i=1;i<5;i++){
			a=in(),b=in();
			if(mx<a+b){
				mx=a+b;
				res='A'+i;
			}
		}
		cout<<res<<" "<<mx<<endl;
	}
	return 0;
}