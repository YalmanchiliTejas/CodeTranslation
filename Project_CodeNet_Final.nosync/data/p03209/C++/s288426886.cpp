#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>

#define DEBUG(x) cout<<#x<<": "<<x<<endl

using namespace std;

int main(){

	long long N, X;

	cin >> N >> X;

	long long b=1;
	long long p=1;
	for(int i =0; i< N; i++){
		b = 2*b +3;
		p = 2*p +1;
	}

	long long ans =0;
	while(X!=0){
		if(X == b) {
			ans += p;
			break;
		}
		if(X == 1) break;
		if((b+1)/2 == X){
			ans += (p+1)/2;
			break;
		}
		if((b+1)/2 < X){
			ans += (p+1)/2;
			X -= (b+1)/2;
		} else {
			X--;
		}
		b = (b-3)/2;
		p = (p-1)/2;
	}

	cout << ans << endl;

	return 0;
}
