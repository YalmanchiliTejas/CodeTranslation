//============================================================================
//Everyone has a different way of thinking, so God Created us
//   Hope You Respect My Way..,Thank You ):
// Author      : Murad
// Name        : Codeforces.cpp & Atcoder.cpp
// Description : Problem name
//============================================================================
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define pi 3.1415926536
#define forn(i,a,b)for(int i=a;i<b;i++)
#define LL long long
#define ULL unsigned long long
#define MP make_pair
#define ff first
#define ss second
#define endl '\n'
#define INF 1e9 + 1
#define _INF INT32_MIN
#define pq priority_queue
#define MM multimap
#define PB push_back
#define vii vector<int>
#define ipair pair<int,int>
#define lpair pair<LL,LL>
#define El3zba ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define modd 1000000007
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
//std::transform(s1.begin(), s1.end(), s1.begin(),::tolower);
char alphz[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
float Euclidean(LL x1, LL x2, LL y1, LL y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
LL gcd(LL a,LL b) {
	return !b ? a : gcd(b, a % b);
}
LL LCM(LL a, LL b) {
	return (a*b) / gcd(a, b);
}
void PrimeFactor(LL n)
{
	while (n % 2 == 0) {
		//printf("%d ", 2);
//		aa.insert(2);
		n /= 2;
	}
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n%i == 0) {
			//printf("%d ", i);
			//aa.insert(i);
			n /= i;
		}
	}
	if (n > 2){
		//printf("%d ", n);
	//	aa.insert(n);
	};
}
bool is_square(LL x) {
	LL l = 0, r = x;
	while (l <= r) {
		LL mid = l + (r - l) / 2;
		if (mid*mid == x)return true;
		if (mid*mid > x)r = mid - 1;
		else l = mid + 1;
	}
	return false;
}
LL power(LL x, LL y)
{
	LL temp;
	if (y == 0)return 1;
	temp = power(x, y / 2);
	if (y % 2 == 0)
		return temp*temp;
	else return x*temp*temp;
}
bool is_Prime(int x) {
	if (x == 2)return 1;
	else if (x % 2 == 0 || x < 2)return 0;
	for (int i = 3; i*i <= x; i += 2)
		if (x%i == 0)return 0;
	return 1;
}
const int N = 105;
int main()
{
	El3zba;
	/***  بسم الله الرحمن الرحيم   ***/
	int n, m;
	cin >> n >> m;
	char s[N][N];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> s[i][j];
	for (int i = 0; i < n; i++)
	{
		bool ok = 0;
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] != '.')
			{
				ok |= 1;
				break;
			}
		}
		if (!ok)
		{
			for (int idx = 0; idx < m; idx++)
				s[i][idx] = '-';
		}
	}
	for (int i = 0; i < m; i++) {
		bool ok = 0;
		for (int j = 0; j < n; j++)
		{
			if (s[j][i] == '.' || s[j][i] == '-')
				continue;
			else {
				ok |= 1; break;
			}
		}
		if (!ok)
		{
			for (int idx = 0; idx < n; idx++)
				s[idx][i] = '-';
		}
	}
	for (int i = 0; i < n; i++)
	{
		bool ok = 0;
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] != '-')
				cout << s[i][j],ok|=1;
		}
		if(ok)
			cout << endl;
	}
	return 0;
}