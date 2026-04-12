#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int R,G,B;

int main()
{
	cin >> R >> G >> B;
	if((G * 10 + B) % 4 == 0){
		puts("YES");
	}
	else{
		puts("NO");
	}

	return 0;
}
