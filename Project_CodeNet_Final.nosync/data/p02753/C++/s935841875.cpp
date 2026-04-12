
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<complex>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using Complex = complex<double>;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1145141919810364364LL;
double PI = acos(-1.0);
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	string S;
	cin >> S;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < 3; i++) { cnt1 += (S[i] == 'A'); cnt2 += (S[i] == 'B'); }
	if (cnt1 == 3 || cnt2 == 3)puts("No");
	else puts("Yes");
	return 0;
}
