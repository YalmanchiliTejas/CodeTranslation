#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<map>
#include<numeric>
#include<stack>
#include<queue>
#include<functional>
#include<cassert>
#include<set>
#include<numeric>
#define rep(a,b) for(ll a=0;a<b;++a)
#define REP(a,b,c,d) for(ll a=b;a<c;a+=d)
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define mod 1000000007
using namespace std;
using ll = long long;
using p_ll = pair<ll, ll>;
int main() {
	int N, K; cin >> N;
	string S; cin >> S;
	cin >> K;
	char c = S[K - 1];
	rep(i, N)if (S[i] != c)S[i] = '*';
	cout << S << endl;
	cin >> N;
}