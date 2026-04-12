#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;

long long mem[3005][3005];
bool vis[3005][3005];
int n;
long long arr[3005];
long long sol(int left , int right , bool st){
	if(left>right)
		return 0;
	if(vis[left][right])
		return mem[left][right];
	vis[left][right] = true;
	long long ret = 0;
	if(!st){
		ret = max(sol(left + 1 , right , st^1) + arr[left] , sol(left , right - 1 ,st^1) + arr[right]);
	}else{
		ret = min(sol(left + 1 , right , st^1) - arr[left] , sol(left , right - 1 ,st^1) - arr[right]);
	}
	return mem[left][right] = ret;
}
int main(){
	cin>>n;
	for(int i= 0;i < n; i++)
		cin>>arr[i];
	cout<<sol(0,n-1,0);
	return 0;
}
