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

	int N, K;
	string S;

	cin >> N >> S >> K;

	for(int i = 0; i < S.size(); i++){
		if(S[i] != S[K-1]){
			S[i] = '*';
		}
	}

	cout << S << endl;

	return 0;
}
