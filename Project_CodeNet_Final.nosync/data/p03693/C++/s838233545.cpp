//#include <bits/stdc++.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <sstream>
#include <complex>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
#define ll long long
#define ull unsigned long long

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
const ll INFLL = 9223372036854775807;
const int MOD = 1e9 + 7;
const double PI=2.0*asin(1.0);

int r, g, b;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(cin>>r>>g>>b){
		if((r*100+g*10+b)%4) puts("NO");
		else puts("YES");
	}

	return 0;
}
