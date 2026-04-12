#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>
#include<algorithm>
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e5+100;
int arr[N],ans[N];
int main(){
	
	
	int n;
	while(cin>>n){
		
		for(int i=1;i<=n;i++)cin>>arr[i];
		
		if(n&1){
			int cnt=n;
			int tmp=2;
			for(int i=1;i<=n;i++){
				ans[i]=arr[cnt];
				if(cnt==1)tmp=-2,cnt=0;
				cnt-=tmp;
				
				
			}
			
		}else{
			
			int cnt=n;
			int tmp=2;
			for(int i=1;i<=n;i++){
				ans[i]=arr[cnt];
				if(cnt==1)tmp=-2;
				cnt-=tmp;
				if(cnt==0)cnt=1;
			
			}
		}
		for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
		cout<<endl;
	
	}
	return 0;
}