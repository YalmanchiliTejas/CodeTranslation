#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
//#include "h.h"
using namespace std;

#define MOD1097 1000000007

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

	int N, K;
	string S;
	cin >> N >> S >> K;
	for(int i = 0; i < S.size(); i ++){
		if(S[i] != S[K - 1])S[i] = '*';
	}
	cout << S << endl;

//"Hiroakimm0415"
	return 0;
}