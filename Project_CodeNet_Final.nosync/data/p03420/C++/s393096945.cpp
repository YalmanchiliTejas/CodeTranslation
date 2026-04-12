#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main() {
	LL N,K;
	cin >> N >> K;
	LL ret=0;
	for(LL b=K+1;b<=N;b++){
		LL p=N/b*(b-K);
		LL r=N%b;
		//cout << p << endl;
		if(r>=K){
			p+=r-max(K,1LL)+1;
		}
		ret+=p;
		//cout << b << ": " << p << endl;
	}
	cout << ret << endl;

	return 0;
}

