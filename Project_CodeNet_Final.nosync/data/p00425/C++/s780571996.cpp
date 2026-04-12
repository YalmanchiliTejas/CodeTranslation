#include <iostream>
#include <string>

using namespace std;

int main(){
	while(1){
		int face[3]={1,2,3};
		int n,result=1;
		cin>>n;
		if(n==0) break;
		for(int i=0;i<n;i++){
			string str;
			cin>>str;
			int tmp=face[0];
			if(str=="North"){
				face[0]=face[1];
				face[1]=7-tmp;
			} else if(str=="East"){
				face[0]=7-face[2];
				face[2]=tmp;
			} else if(str=="West"){
				face[0]=face[2];
				face[2]=7-tmp;
			} else if(str=="South"){
				face[0]=7-face[1];
				face[1]=tmp;
			} else if(str=="Right"){
				tmp=face[1];
				face[1]=face[2];
				face[2]=7-tmp;
			} else if(str=="Left"){
				tmp=face[1];
				face[1]=7-face[2];
				face[2]=tmp;
			}
			result+=face[0];
		}
		cout<<result<<endl;
	}
	return 0;
}