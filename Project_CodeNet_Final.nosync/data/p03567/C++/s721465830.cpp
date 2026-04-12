#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<map>
#include<numeric>
#include<queue>
#include<functional>
#include<cassert>
#include<set>
#define rep(a,b) for(int a=0;a<b;++a)
#define REP(a,b,c,d) for(int a=b;a<c;a+=d)
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define mod 1000000007
using namespace std;
using ll = long long;
using p_i = pair<int, int>;
int main() {
	string S; cin >> S;
	rep(i, S.size()) {
		if (i != S.size() - 1) {
			if (S[i] == 'A'&&S[i+1]=='C') {
				yes;
				return 0;
			}
		}
	}
	no;
}