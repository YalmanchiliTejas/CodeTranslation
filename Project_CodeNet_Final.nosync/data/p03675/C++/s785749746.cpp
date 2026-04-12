#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <iomanip>
#include <math.h> 
#include <stack>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <tuple>
#include <cctype>
#include <ctype.h>
#include <set>
#include <sstream>
#include <time.h>
using namespace std;
#define int long long
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define l1 list[index]
#define l2 list[index - 1]
#define l3 list[index + 1]
#define iif(i,j) ((i<0 && j<0) || (i>0 && j>0)) ? true : false 
typedef long long ll;
typedef pair<int, int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
typedef pair<pint, int> P1;
typedef pair<int, pint> P2;
typedef pair<pint, pint> PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD = 1000000007;
const ll INF = 1e18;
int ca[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };




signed main() {
	int n, h, w;
	//vector<int>list(200005, 0);
	int list2[500005];
	int list[300005];
	static int kijyun = 250000;
	int right = 1, left = 1;

	memset(list2, -1, sizeof(list2));


	cin >> n;

	for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			list[i] = num;
	}

	int num = n;

	list2[kijyun] = list[n - num];
	num--;


	while (num>0)
	{
		if (num % 2 == 0) {
			list2[kijyun + right] = list[n - num];
			right++;
		}
		else {
			list2[kijyun - left] = list[n - num];
			left++;
		}

		num--;
	}

	int cnt = 0;

	for (int i = 0; i < 450000; i++) {
		if (list2[i] != -1) {
			cout << list2[i];
			cnt++;
			if (cnt != n) {
				cout << " ";
			}
		}
	}
	cout << endl;
	

	//vector<int>list2;

	//for (int i = 0; i < n; i++) {
	//	int num;
	//	cin >> num;

	//	if (i % 2 == 1) {
	//		//list2.insert(list2.begin(), list[i]);
	//		list2.insert(list2.begin(), num);
	//	}
	//	else {
	//		//list2.push_back(list[i]);
	//		list2.push_back(num);
	//	}
	//}

	//if (n % 2 == 0) {
	//	for (int i = 0; i < n; i++) {
	//		cout << list2[i];
	//		if (i != n - 1) {
	//			cout << " ";
	//		}
	//	}
	//	cout << endl;
	//}
	//else {
	//	for (int i = n - 1; i >= 0; i--) {
	//		cout << list2[i];
	//		if (i >= 1) {
	//			cout << " ";
	//		}
	//	}
	//	cout << endl;
	//}







	return 0;
}