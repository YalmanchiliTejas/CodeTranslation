#include<bits/stdc++.h>
using namespace std;

long long n,x;

long long dfs(long long n, long long x)
{
	if(n==0) {
		if(x > 0) return 1ll;  //如果x>0，左边都是B了 
			else return 0;  //之前吃光了 
	}
	if(x <= pow(2,n+1)-2) return dfs(n-1,x-1);   //汉堡包对称的，不到中间的话，递归n-1规模的子问题，最右边的B去掉，所以x-1 
		else return pow(2,n) + dfs(n-1,x - pow(2,n+1) + 1); //如果超过对称部分，则在n-1规模子问题中寻找剩下部分能吃多少p 
} 


int main()
{
	cin >> n >> x;
	cout << dfs(n,x);
	return 0;
}