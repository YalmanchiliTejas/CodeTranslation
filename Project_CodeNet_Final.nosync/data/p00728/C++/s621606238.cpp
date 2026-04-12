#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while(1){
		cin>>n;
		if(n==0)
		break;
		int x[n],ma=0,mi=0,ans=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
			ans+=x[i];
			if(i==0)
			mi=x[i];
			ma=max(x[i],ma);
			mi=min(x[i],mi);
		}
		cout<<(ans-(ma+mi))/(n-2)<<endl;
	}
return 0;
}