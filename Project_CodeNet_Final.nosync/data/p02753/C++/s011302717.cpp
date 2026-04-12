#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp(a, b) make_pair(a, b)
#define ls (rt << 1)
#define rs (rt << 1 | 1) 
typedef pair<int, int> pii; 
const ll mod = 1e9 + 7;
template <class T> T lowbit(T x){return ((x)&(-(x)));}
const int maxn = 2e5 + 10;
int t, n, a[maxn];
int main()
{
	string s;
	cin >> s;
	if(s[0] == s[1] && s[1] == s[2])
		puts("No");
	else
		puts("Yes"); 
	return 0;
}