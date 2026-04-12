#include<iostream>
using namespace std;

int main(){
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int str,len,n,ctop=0;
		cin>>str>>len>>n;
		for(int j=0;j<n;j++){
			int typ,cst,crt=str;
			double rate;
			cin>>typ>>rate>>cst;
			if(typ==1){
				for(int k=0;k<len;k++){
					crt+=crt*rate-cst;
				}
			}else{
				int add=0;
				for(int k=0;k<len;k++){
					add+=crt*rate;
					crt-=cst;
				}
				crt+=add;
			}
			if(ctop<crt){
				ctop=crt;
			}
		}
		cout<<ctop<<endl;
	}
	return 0;
}