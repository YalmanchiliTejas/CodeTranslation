#define _USE_MATH_DEFINES
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<climits>
#include<set>
#include<map>
#include<cmath>
#include<iomanip>
#include<iterator>
#include<queue>
#include<stack>
#include<cctype>
#include<deque>
#include<time.h>
#include<bitset>
#include<random>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
#include<random>

//by Skeef79

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define en '\n'
#define for0(i,n) for(int i = 0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define vec vector
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;



vector<ll> getdiv(int k) {
	vector<ll> res;
	for (int i = 1; i * i <= k; i++) {
		if (k % i == 0) {
			res.push_back(i);
			res.push_back(k / i);
			if (i == k / i)res.pop_back();
		}
	}
	sort(res.begin(), res.end());
	return res;
}


int main()
{
	//int n; cin >> n;
	//string s;
	//cin >> s;
	//int left = 0, right = 0;
	//bool previsright = false;
	//stack<char> st; // 8 (()))(() 6 (())() ))(()()()()( 8
	////))((())(

	//ll ans = 0;
	//ll start = -1;
	//for (int i = 0; i < n; i++) {
	//	if (s[i] == '(') {
	//		st.push('(');
	//		left++;
	//		if (right == left) {
	//			ans += i - start + 1;
	//			for (int j = 0; j < left; j++) st.pop();
	//			left = 0;
	//			right = 0;
	//			start = -1;
	//			
	//		}
	//		
	//	}
	//	else {
	//		if (!st.empty() && st.top() == '(') {
	//			left--;
	//			st.pop();
	//		}
	//		else {
	//			if (start == -1) {
	//				start = i;
	//				right++;
	//			}
	//			else {
	//				right++;
	//			}
	//		}
	//		

	//	}
	//}

	//if (left == 0 && right == 0)
	//	cout << ans;
	//else cout << -1;

	string s;
	cin >> s;
	if (s[0] != s[1] || s[1] != s[2]) cout << "Yes";
	else cout << "No";








}