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
	cin >> N;
	vector<lint>A(N);
	rep(i, N) {
		cin >> A[i];
	}
	sort(A);
	if (N % 2 == 0) {
		deque<lint>B;
		deque<lint>C;
		vector<lint>D;
		rep(i, N / 2) {
			B.push_back(A[i]);
		}
		B.push_front(B.back());
		B.pop_back();
		rep(i, N / 2) {
			C.push_back(A[i + N / 2]);
		}
		C.push_back(C.front());
		C.pop_front();
		rep(i, N) {
			if (i % 2 == 0) {
				D.push_back(B.front());
				B.pop_front();
			}
			else {
				D.push_back(C.front());
				C.pop_front();
			}
		}
		lint ans = 0;
		rep(i, N-1) {
			ans += abs(D[i] - D[i + 1]);
		}
		cout << ans << endl;
	}
	else {
		vector<lint>AA = A;
		reverse(A);
		vector<lint>SA = A;
		deque<lint>B;
		deque<lint>C;
		vector<lint>D;
		deque<lint>SB;
		deque<lint>SC;
		vector<lint>SD;

		rep(i, (N - 1) / 2) {
			B.push_back(AA[i]);
		}
		B.push_front(B.back());
		B.pop_back();
		rep(i, (N + 1) / 2) {
			C.push_back(AA[i + (N - 1) / 2]);
		}
		C.push_back(C.front());
		C.pop_front();
		rep(i, N) {
			if (i % 2 != 0) {
				D.push_back(B.front());
				B.pop_front();
			}
			else {
				D.push_back(C.front());
				C.pop_front();
			}
		}
		lint ans1 = 0;
		rep(i, N - 1) {
			ans1 += abs(D[i] - D[i + 1]);
		}

		rep(i, (N - 1) / 2) {
			SB.push_back(SA[i]);
		}
		SB.push_front(SB.back());
		SB.pop_back();
		rep(i, (N + 1) / 2) {
			SC.push_back(SA[i + (N - 1) / 2]);
		}
		SC.push_back(SC.front());
		SC.pop_front();
		rep(i, N) {
			if (i % 2 != 0) {
				SD.push_back(SB.front());
				SB.pop_front();
			}
			else {
				SD.push_back(SC.front());
				SC.pop_front();
			}
		}
		lint ans2 = 0;
		rep(i, N - 1) {
			ans2 += abs(SD[i] - SD[i + 1]);
		}
		cout << max(ans1, ans2) << endl;
	}
}