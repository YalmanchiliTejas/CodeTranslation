#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <cmath>
#include <deque>
#include <bitset>
#define ll long long
#define PI 3.1415926535897932384626433832795
#define read(x) scanf("%d",&x);
#define readll(x) cin>>x;
#define FOR(x,a,b) for(int x=a;x<b;x++)
#define MP make_pair
#define PB push_back
#define pii pair<int,int>
#define readN(N,X) for(int i=0;i<N;i++) cin>>X[i];
#define pff pair<double,double>
using namespace std;

ll N;
ll A[55];

int main() {
	cin>>N;
	ll res = 0;
	readN(N,A);
	bool ganti = 1;
	while(ganti){
		ganti = 0;
		ll naik = 0;
		FOR(i,0,N){
			if (A[i] < N) continue;
			ganti = 1;
			ll bagi = A[i]/N;
			A[i] -= (N + 1) * bagi;
			//cout<<bagi<<endl;
			res += bagi;
			naik += bagi;
		}
		FOR(i,0,N) A[i] += naik;
	}
	cout<<res<<endl;
	
}