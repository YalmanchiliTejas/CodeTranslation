#include <iostream>
#include <string>
using namespace std;
int main(){
	string a;
	while(cin>>a){
		if(a=="#") break;
		int len=a.size();
		int k=0,m=2;
		for(int i=0;i<len;i++){
			if(a[i]=='q'||a[i]=='w'||a[i]=='e'||a[i]=='r'||a[i]=='t'||a[i]=='a'||a[i]=='s'||a[i]=='d'||a[i]=='f'||a[i]=='g'||a[i]=='z'||a[i]=='x'||a[i]=='c'||a[i]=='v'||a[i]=='b'){
				if(m==1){
					k++;
				}
				m=0;
			}
			else{
				if(m==0){
					k++;
				}
				m=1;
			}
		}
		cout<<k<<endl;
	}
    return 0;
}