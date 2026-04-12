#include<iostream>
using namespace std;
int main(){
	int n,a,b,c,x;
	while(cin>>n>>a>>b>>c>>x,n){
		int ans=0,cnt=0,d[n];
		for(int i=0;i<n;i++)
		cin>>d[i];
		while(ans<=10000){
			if(d[cnt]==x)
			cnt++;
			if(cnt==n)
			break;
			x=(a*x+b)%c;
			ans++;
		}
		if(ans<=10000)
		cout<<ans<<endl;
		else
		cout<<-1<<endl;
	}
	return 0;
}