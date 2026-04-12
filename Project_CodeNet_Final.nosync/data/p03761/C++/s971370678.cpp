#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#define MP(a, b) make_pair(a, b)
#define POWER9 1000000000
#define MOD POWER9+7
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define LL_MIN (LL)-9223372036854775807
#define LL_MAX (LL)9223372036854775807
#define PI 3.14159265359

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(9);

	int N;
	cin >> N;
	int ans[26];
	for(int i=0; i<26; i++) ans[i] = INT_MAX;
	for(int i=0; i<N; i++){
		string S;
		cin >> S;
		int c[26] = {};
		for(int j=0; j<S.size(); j++){
			c[S[j]-'a']++;
		}
		for(int j=0; j<26; j++){
			ans[j] = min(ans[j], c[j]);
		}
	}
	string a = "";
	for(int i=0; i<26; i++){
		for(int j=0; j<ans[i]; j++){
			a += (char)('a'+i);
		}
	}
	cout << a << endl;

	return 0;
}
