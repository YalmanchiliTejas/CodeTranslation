#include<iostream>
#include<string>
using namespace std;
int main(void){
	string right="yuiophjklnm";
	string a;
	while(1){
		cin>>a;
		if(a=="#")break;
		int b=0,c=0,ans=0;
		for(int i=0;i<a.size();i++){
			for(int j=0;j<right.size();j++){
				if(a[i]==right[j]){
					b=1;
				}
			}
			if(b!=1)b=-1;
			if(b!=c)ans++;
			c=b;
			b=-1;
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
