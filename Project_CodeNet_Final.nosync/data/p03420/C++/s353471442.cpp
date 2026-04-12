/* ***********************************************
Author        :ACagain
Created Time  :2018/4/21 11:50:24
File Name     :dong.cpp
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define pii pair<int,int>
#define mp make_pair
#define ll long long
#define INF 0x3f3f3f3f
const int maxn=1e4+5;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   	ll n,k;
	ll ans=0;
	cin>>n>>k;
	if(k==0)
	{
		ans=n*n;
	}
	else
	for(int i=k+1;i<=n;i++)
	{
		ll b=i;
		ans+=n/b*(b-k);
		if(n%b>=k)
		  ans+=n%b-k+1;
	}
	cout<<ans<<endl;
	return 0;
}
