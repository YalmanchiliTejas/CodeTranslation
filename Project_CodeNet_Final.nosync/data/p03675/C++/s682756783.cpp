#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <sstream>
#include <cstring>
#include <stack>
using namespace std;
#define MP make_pair
#define PB push_back
const int INF=1e9;

int n,a[200005],b[200005];

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	int p=1,q=n;
	for (int i=1;i<=n;i++)
	{
		if (i%2) b[p++]=a[n+1-i]; else b[q--]=a[n+1-i];
	}
	for (int i=1;i<=n;i++) cout<<b[i]<<" ";
	return 0;
}