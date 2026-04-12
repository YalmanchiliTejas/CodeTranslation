#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,x;
	cin>>n>>x;
	long long all=(1LL<<(n+2))-3;
	long long pat[51];
	pat[0]=1;
	for(int i=0;i<n;i++){
		pat[i+1]=pat[i]*2+1;
	}
	long long idx=n;
	long long ans=0;
	while(x>0){
      	if(idx==0){
          	ans++;
          	break;
        }else if((all+1)/2==x){
			ans+=pat[idx-1]+1;
			break;
		}else if((all+1)/2<x){
			ans+=pat[idx-1]+1;
			x-=(all+1)/2;
		}else{
          	x--;
		}
		all-=3;
		all/=2;
		idx--;
	}
	cout<<ans<<endl;
	return 0;
}
