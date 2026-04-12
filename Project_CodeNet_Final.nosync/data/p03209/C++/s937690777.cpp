#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <istream>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

ll s[51];
ll p[51];

ll f(int N, ll X){
	if(N==0){
		return (X<=0 ? 0 : 1);
	}else if(X <= 1+s[N-1]){
		return f(N-1,X-1);
	}else{
		return p[N-1] + 1 + f(N-1, X-1-s[N-1]-1);
	}
}


int main(){
	int N;
	ll X;
	cin >> N >> X;
	s[0] = 1;
	p[0] = 1;
	for(int i=1;i<=N;i++) s[i] = 2*s[i-1]+3;
	for(int i=1;i<=N;i++) p[i] = 2*p[i-1]+1;
	
	cout << f(N,X) << endl;

	
	return 0;
}