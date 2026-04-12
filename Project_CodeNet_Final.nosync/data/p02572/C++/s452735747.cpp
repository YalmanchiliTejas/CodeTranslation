#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <ctime>
#define ll long long
#define inf 0x3f3f3f3f
#define N 200010
#define mod 1000000007
#define int long long
//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int a[N];

signed main(){
	int n,sum=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
        sum=(sum+a[i])%mod;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+a[i]*(sum+mod-a[i]))%mod;
    }
    ans=ans*500000004%mod;
    printf("%lld\n",ans);
	return 0;
}
