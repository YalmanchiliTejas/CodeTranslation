#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;
pair<long long,int> d[200000];
int main(){
	int n,ans=0,cnt=0;
	cin>>n>>d[0].X;
	d[0].Y=0;
	for(int i=1;i<n;i++){
		cin>>d[i].X;
		d[i].X+=d[i-1].X;
		d[i].Y=i;
	}
	sort(d,d+n);
	for(int i=1;i<n;i++){
		if(d[i].X==0)ans=max(ans,d[i].Y+1);
		if(d[i-1].X==d[i].X)cnt+=d[i].Y-d[i-1].Y;
		else cnt=0;
		ans=max(cnt,ans);
	}
	if(d[0].X==0)ans=max(ans,d[0].Y+1);
	cout<<ans<<endl;
	return 0;
}