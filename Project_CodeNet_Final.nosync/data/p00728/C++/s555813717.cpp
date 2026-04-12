#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
	int n;
	while(cin>>n and n>0){
		int s[n]; rep(i,n) cin>>s[i];
		sort(s,s+n);
		int sum=0;
		for(int i=1;i<n-1;i++){
			sum+=s[i];
		}
		int ans=sum/(n-2);
		cout<<ans<<endl;
	}

	return 0;
}

