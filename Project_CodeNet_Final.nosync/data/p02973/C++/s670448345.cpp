//#pragma GCC optimize("Ofast")
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define zy 2333333
#define bql 2147483647
using namespace std;
int n,B[100005],a[100005],len;
int main()
{
	  fast;
    cin>>n;
    for (int i=1;i<=n;i++)
       cin>>a[i];
    B[1]=-a[1],len=1;
    for (int i=2;i<=n;i++)
    {
        if (-a[i]>=B[len]) 
				   B[++len]=-a[i];
        else
        {
            int pos=upper_bound(B+1,B+len,-a[i])-B;
            B[pos]=-a[i];
        }
    }
    cout<<len<<endl;
}
