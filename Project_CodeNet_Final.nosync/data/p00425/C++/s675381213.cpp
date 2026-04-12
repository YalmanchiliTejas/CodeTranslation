#include <iostream>

using namespace std;

int main(){
	int n;
	while(cin >> n, n){
		char d[]="123456",s[9];
		int dir,rot=0,res=1,tmp;
		for(int i=0;i<n;i++){
			cin >> s;
			if(*s%6-4){
				dir=(*s-78?*s%5-1:0)+rot&3;
				dir=dir+1+(1-dir%2*2)*(dir/2);
				tmp=*d,*d=d[dir],d[dir]=d[5],d[5]=d[5-dir],d[5-dir]=tmp;
			} else rot+=*s+3;
			res+=*d-48;
		}
		printf("%d\n",res);
	}
}