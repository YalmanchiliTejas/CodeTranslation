#include <iostream>
using namespace std;
int main(void){
	int n;
	while(cin>>n,n){
		int top=1,south=2,east=3,sum=1;
		for(int i=0;i<n;++i){
			string s;
			cin>>s;
			if(s=="North"){
				int tmp=top;
				top=south;
				south=7-tmp;
			}else if(s=="East"){
				int tmp=east;
				east=top;
				top=7-tmp;
			}else if(s=="West"){
				int tmp=top;
				top=east;
				east=7-tmp;
			}else if(s=="South"){
				int tmp=south;
				south=top;
				top=7-tmp;
			}else if(s=="Right"){
				int tmp=south;
				south=east;
				east=7-tmp;
			}else if(s=="Left"){
				int tmp=east;
				east=south;
				south=7-tmp;
			}
			sum+=top;
		}
		cout<<sum<<endl;
	}
}