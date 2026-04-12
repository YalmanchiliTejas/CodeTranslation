#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
//#include "h.h"
using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define pm(first, second) pb(mp(first, second))
#define SPACE " "
#define fpf first.first
#define fps first.second
#define spf second.first
#define sps second.second

#define all(X) (X).begin(), (X).end()

int main(){

	int N;
	cin >> N;
	int h, m = 0;
	int ans = 0;
	for(int i = 0; i < N; i ++){
		cin >> h;
		if(m <= h){
			ans ++;
			m = h;
		}
	}
	cout << ans << endl;

	return 0;
}