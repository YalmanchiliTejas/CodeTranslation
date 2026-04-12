#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>  
#include<cstdio>  
#include<fstream>  
#include<iomanip>
#include<algorithm>  
#include<cmath>  
#include<deque>  
#include<vector>
#include<bitset>
#include<queue>  
#include<string>  
#include<cstring>  
#include<map>  
#include<stack>  
#include<set>
#include<functional>
#define pii pair<int, int>
#define mod 1000000007
#define mp make_pair
#define pi acos(-1)
#define eps 0.00000001
#define mst(a,i) memset(a,i,sizeof(a))
#define all(n) n.begin(),n.end()
#define lson(x) ((x<<1))  
#define rson(x) ((x<<1)|1) 
#define inf 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
deque<int>a;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i, j, k, m, n;
	cin >> n;
	int mode = n & 1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> k;
		if (mode)a.push_front(k);
		else a.push_back(k);
		mode ^= 1;
	}
	for (int i = 0; i < a.size()-1; ++i)
	{
		cout << a[i] << " ";
	}
	cout << a[(int)a.size() - 1];
	return 0;
}

