#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define mp make_pair
#define IP pair<int,int>
#define enld endl

int main() {
	lint N;
	while (cin >> N, N != 0) {
		vector<vector<lint>>A(N, vector<lint>(N));
		lint I = N / 2 + 1;
		lint J = N / 2;
		rep(i, N * N) {
			while (A[I][J] != 0) {
				I++;
				J--;
				if (I == N) {
					I = 0;
				}
				if (J == -1) {
					J = N - 1;
				}
			}
			A[I][J] = i + 1;
			I++;
			J++;
			if (I == N) {
				I = 0;
			}
			if (J == N) {
				J = 0;
			}
		}
		rep(i, N) {
			rep(j, N) {
				cout << right << setw(4) << A[i][j];
			}
			cout << endl;
		}
	}
}
