#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define int long long
using namespace std;

signed main(){
	int a,b,c,x,y,ans=0;
	cin>>a>>b>>c>>x>>y;
	while(1){
		if(!x&&!y)break;
		if(!x){
			ans+=(c*2<b)?c*2:b;
			y--;
		}else if(!y){
			ans+=(c*2<a)?c*2:a;
			x--;
		}else{
			ans+=((c*2<a+b)?c*2:a+b);
			x--;y--;
		}
	}
	cout<<ans<<endl;
	return 0;
}