#include <bits/stdc++.h>
using namespace std;



int main()
{	
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	// #ifndef ONLINE_JUDGE
 //    	freopen("input.txt", "r", stdin);
 //    	freopen("output.txt", "w", stdout);
	// #endif
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    	cin>>a[i];
    int ans=1;
    int c = a[0];
    for(int i=1;i<n;i++){
    	if(a[i]>=c){
    		ans++;
    		c=a[i];
    	}
    }
    cout<<ans;
}