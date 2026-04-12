/*
 * ===================================================================
 *
 *       Filename:  atb.cpp
 *
 *           Link:  
 *
 *        Created:  2019/04/20 20时03分25秒
 *
 *         Author:  duny31030 , duny31030@126.com
 *   Organization:  duny31030.top
 *
 * ===================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n,k;
char a[20];

int main()
{
	cin >> n;
	cin >> a;
	cin >> k;
	char tmp = a[k-1];
    for(int i = 0;i < n;i++)
	{
		if(a[i] != tmp)
		{
			cout << "*";
		}
		else 
		{
			cout << a[i];
		}
	}

    return 0;
}

