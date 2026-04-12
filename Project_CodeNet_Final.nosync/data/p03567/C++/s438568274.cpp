#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = int(l);i < int(r);i++)
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int N;
string S;

int main()
{
	cin >> S;
	N = S.size();

	FOR(i,0,N - 1){
		if(S.substr(i,2) == "AC"){
			puts("Yes");
			return 0;
		}
	}
	puts("No");

	return 0;
}
