#include<bits/stdc++.h>
using namespace std;

#define INF (1<<30)

int main(){
	int a,b,AB,x,y;	cin>>a>>b>>AB>>x>>y;

	int limit=max(x,y)*2;

	int ans=INF;
	for(int i=0; i<=limit; i++){
		// ABピザを買うべき数を全探索。
		int need_A=max(0, x-(i/2)), need_B=max(0, y-(i/2));
		int cost=(i*AB)+(need_A*a)+(need_B*b);

		ans=min(ans,cost);
	}

	cout<<ans<<endl;

	

	return 0;
}
