#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
int l,r,n,a[55];
int main(){
	while(1){
		cin>>n>>l>>r;if(n==0) return 0;
		rep(i,n) cin>>a[i];
		int ans = 0;
		for(int x=l;x<=r;x++){
			rep(i,n){
				if(x%a[i] == 0){
					if(i%2 == 0) ans++;
					goto nxt;
				}
			}
			if(n%2 == 0) ans++;
		nxt:;
		}
		cout << ans << endl;
	}
}

