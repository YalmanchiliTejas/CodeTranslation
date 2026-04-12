#include<iostream>
#include<string>
using namespace std;
int main(){
	string str,st[11]={"h","i","j","k","l","m","n","o","p","y","u"};
	while(1){
		str.clear();
		cin>>str;
		int s=0,ans=0,f=0;
		if(str=="#")
		break;
		for(int i=0;i<11;i++){
			if(str[0]==st[i][0]){
				f=1;
				s=2;
			}
		}
		if(f==0)
		s=1;
		for(int i=1;i<str.size();i++){
			f=0;
			for(int j=0;j<11;j++){
				if(str[i]==st[j][0]){
					f=1;
					break;
				}
			}
			if(f==0 && s==2 || f==1 && s==1)
			ans++;
			if(f==1)
			s=2;
			else
			s=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}