#include<iostream>
using namespace std;
int n,h[25],ans=1,pd;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		pd=1;
		cin>>h[i];
		if(i>=2){
			for(int j=1;j<i;j++)
				if(h[i]<h[j])
					pd=0;
			if(pd)
				ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}