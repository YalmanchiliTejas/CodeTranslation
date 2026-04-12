#include<cstdio>
#include<iostream>
using namespace std;
int main(void){
	int flg=1,i,max,a,b,mise;
	char s[]="ABCDE";
	while(1){
		max=-1;
		for(i=0;i<5;i++){
			cin>>a;
			cin>>b;
			if(max<a+b){
				mise=i;
				max=a+b;
			}
			if(max==0){
				flg=0;
				break;
			}
		}
		if(flg==0) break;
		cout<<s[mise]<<' '<<max<<endl;
	}
	return 0;
}