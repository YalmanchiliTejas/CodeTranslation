#include<string>
#include<iostream>
using namespace std;
int main(){
	int n;
	
	while(cin>>n,n){
	bool a[100000]={0};
	int ans=0;
	for(int i=1;i<=n;i++){
		bool tmp;
		cin>>tmp;
		if(i%2==1)a[i-1]=tmp;
		else{
			if(tmp==a[i-2]){//右端とおくやつが同じなら
				a[i-1]=tmp;
			}
			else{
				//cout<<"i"<<i;
				int j=i-2;
				bool ki=tmp;
				while(true){
					if(tmp!=a[j]){
						a[j]=tmp;
					}
					else if(tmp==a[j]||j<0) break;
					j--;
				}
				a[i-1]=tmp;
			}
		}
		}
		for(int i=0;i<n;i++)if(a[i]==0)ans++;
			cout<<ans<<endl;
	}
	return 0;
}