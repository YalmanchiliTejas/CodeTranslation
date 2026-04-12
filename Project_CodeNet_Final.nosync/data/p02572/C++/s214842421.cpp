#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

const ll mod = 1000000007;

int main()
{
	ll N;
	ll A[200200];
	ll sum = 0;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		sum += A[i];
	}
	ll ans = 0;
	for(int i = 0; i < N; i++){
		sum -= A[i];
		ans += (sum % mod) * A[i];
		ans %= mod;
	}
	cout << ans <<endl;
	
	return 0;
}
