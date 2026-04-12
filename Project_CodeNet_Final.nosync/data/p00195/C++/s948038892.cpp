#include <iostream>
using namespace std;

int main(){
	int sm,sn,s[5],i,tmp;
	char a[6]="ABCDE";
	while(cin>>sm>>sn,sm+sn){
		s[0]=sm+sn;
		int ss[5]={};
		for(i=1;i<5;i++){
			cin>>sm>>sn;
			s[i]=sm+sn;
		}
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(i!=j&&s[i]>s[j])ss[i]++;
			}
			if(ss[i]==4)cout<<a[i]<<' '<<s[i]<<endl;
		}
	}
}