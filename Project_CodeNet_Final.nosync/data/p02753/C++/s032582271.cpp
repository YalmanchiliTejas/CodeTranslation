#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector> 
#include <cstring>
#include <queue>
#include <ctime>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const ll INF = 10e16;
const int maxN = 500010;
const int maxD = 15;
const int maxH = 100; 
const int MOD = 1000000007;

int a[maxN]; 
int main()
{

	string s;
	cin>>s;
	if(s[0] != s[1] || s[1] != s[2] || s[2] != s[0])
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}