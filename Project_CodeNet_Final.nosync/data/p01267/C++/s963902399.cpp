#include <iostream>
#include <algorithm>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
	int n,a,b,c,x;
	while(cin>>n>>a>>b>>c>>x and n>0){
		int y[n]; rep(i,n) cin>>y[i];
		int roll=0,ans=-1;
		rep(i,10001){
			if(x==y[roll]) roll++;
			if(roll==n){
				ans=i; break;
			}
			x=(a*x+b)%c;
		}
		cout<<ans<<endl;
	}
	return 0;
}

