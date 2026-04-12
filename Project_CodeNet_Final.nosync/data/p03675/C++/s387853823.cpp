#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int arr[maxn];
int ans[maxn];
int n; 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
	for(int i=1;i<=n;i++)
	    cin >> arr[i];
	int cur = 0;
	int l = 0 , r = 1; 
	for(int i=n;i>=1;i--)
	{
		if(cur&1)
		    ans[n-r++] = arr[i];
		else 
		    ans[l++] = arr[i];
		cur++; 
	} 
	for(int i=0;i<n;i++)
	{
		if(i!=0)
		    cout << " ";
		cout << ans[i]; 
	} 
	cout << endl; 
    return 0;
}
