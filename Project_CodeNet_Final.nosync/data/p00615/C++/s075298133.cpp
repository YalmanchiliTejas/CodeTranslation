#include<iostream>
#include<algorithm>
using namespace std;
  
int a[20000];

int main(){
	int n,m;
	while(cin>>n>>m&&(n||m)){
		int ans=0;
		for(int i=0;i<n+m;i++)cin>>a[i];
		sort(a,a+n+m);
		int prev=0;
		for(int i=0;i<n+m;i++){
			ans=max(ans,a[i]-prev);
			prev=a[i];
		}
		cout<<ans<<endl;
	}
    return 0;
}