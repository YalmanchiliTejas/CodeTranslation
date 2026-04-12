#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <ctime>
#include <queue>
#include <sstream>
#include <utility>
#include <bitset>

using namespace std;

#define MP make_pair 
#define PB push_back 
#define INF (1000000007) 
#define eps 1e-8

typedef pair<int,int> pii ;
typedef long long ll ;

int n;
int a[200005];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n%2)
	{
		for(int i=n;i>=1;i--) if(i%2) cout<<a[i]<<" ";
		for(int i=1;i<=n;i++) if(i%2==0) cout<<a[i]<<" ";
	}
	else
	{
		for(int i=n;i>=1;i--) if(i%2==0) cout<<a[i]<<" ";
		for(int i=1;i<=n;i++) if(i%2) cout<<a[i]<<" ";
	}
	return 0;
}