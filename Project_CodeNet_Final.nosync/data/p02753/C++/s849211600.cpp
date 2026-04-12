/*
Keep clam  Believe youself
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<stack>
#include<set>
#include<cmath>
#define Xiaobo main
#define DEBUG(x) cerr<<#x<<": "<<(x)<<endl
using namespace std;
const int maxn=2e5+7;
const int mod=1e9+7;
const double eps=1e-15;
const double pi=acos(-1);
const int INF=0x3f3f3f3f;
typedef long long ll;
ll read(){ll c = getchar(),Nig = 1,x = 0;while(!isdigit(c) && c!='-')c = getchar();if(c == '-')Nig = -1,c = getchar();while(isdigit(c))x = ((x<<1) + (x<<3)) + (c^'0'),c = getchar();return Nig*x;}
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b);}
//别急 dp找状态 问题看看本身的规律 贪心找方法
int Xiaobo()
{
	string s;
	cin>>s;
	int f1=0,f2=0;
	for(int i=0;i<(int)s.size();i++) {
		if(s[i]=='A') f1++;
		if(s[i]=='B') f2++;
	}
	if(f1&&f2) puts("Yes");
	else puts("No");
}