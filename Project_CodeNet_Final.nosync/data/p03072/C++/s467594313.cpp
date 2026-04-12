#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105];
int ans;
int main(void){
	int n; cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		bool k=true;
		for(int j=0;j<i;j++){
			if(a[j]>a[i]){
				k=false;
			}
		}
		if(k){
				ans++;
			}
	}
	cout<<ans<<endl;
	
}
