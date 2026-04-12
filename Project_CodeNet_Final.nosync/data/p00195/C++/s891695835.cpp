#include<iostream>

using namespace std;

int main(){
	int a[2][5];
	char ans[5]={'A','B','C','D','E'};
	int max,s,m;
	while(cin>>a[0][0]>>a[1][0],a[0][0]!=0){
		max=a[0][0]+a[1][0];
		m=0;
		for(int i=1;i<5;i++){
			cin>>a[0][i]>>a[1][i];
				s=a[0][i]+a[1][i];
				if(s>max){max=s;m=i;}
		}
		cout<<ans[m]<<" "<<max<<endl;
	}

}