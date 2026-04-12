#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	while(cin>>n,n){
		int f=2,r=3,u=1,sum=0;
		string s;
		for(int i=0;i<n;i++){
			int nf,nr,nu;
			cin>>s;
			if(s=="North"){
				nr=r;
				nf=7-u;
				nu=f;
			}else if(s=="East"){
				nr=u;
				nf=f;
				nu=7-r;
			}else if(s=="West"){
				nr=7-u;
				nf=f;
				nu=r;
			}else if(s=="South"){
				nr=r;
				nf=u;
				nu=7-f;
			}else if(s=="Right"){
				nr=7-f;
				nf=r;
				nu=u;
			}else{
				nr=f;
				nf=7-r;
				nu=u;
			}
			f=nf;r=nr;u=nu;
			sum+=u;
		}
		cout<<sum+1<<endl;
	}
	return 0;
}