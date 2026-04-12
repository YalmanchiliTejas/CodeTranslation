#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;
typedef long long ll;

int main(){
	ll n,x;
	cin>>n>>x;
	ll num[n+1],paty[n+1];
	num[0]=paty[0]=1;
	loop(i,1,n+1){
		num[i]=num[i-1]*2+3;
		paty[i]=paty[i-1]*2+1;
	}
	ll ans=0;
	for(int i=n;i>=1;i--){
		if(x==0)break;
		if(x>num[i-1]+1){
			ans+=paty[i-1];
			x-=num[i-1]+1;
			if(x==0)break;
			if(x==1){
				ans++;
				break;
			}
			if(x==num[i-1]+1||x==num[i-1]+2){
				ans+=paty[i-1]+1;
				break;
			}
			ans++;
			x--;
		}else{
			if(x==0||x==1)break;
			x--;
			if(x==num[i-1]){
				ans+=paty[i-1];
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}