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

int main()
{
	ll N, X, M;
	cin >> N >> X >> M;
	ll sum = 0;
	ll count = 0;
	ll now = X;
	ll next = -1;
	while(count < N && count < M){
		sum += now;
		next = (now * now) % M;
		count++;
		now = next;
	}
	if(count == N){
		cout << sum << endl;
		return 0;
	}
	
	// 
	ll ans = sum;
	N -= count;
	
	sum = 0;
	count = 0;
	X = now;
	next = -1;
	while(count < N && next != X){
		sum += now;
		next = (now * now) % M;
		count++;
		now = next;
	}
	
	ans += sum * (N / count);
	for(int i = 0; i < N % count; i++){
		ans += now;
		now = (now * now) % M;
	}
	
	cout << ans << endl;
	
	return 0;
}
