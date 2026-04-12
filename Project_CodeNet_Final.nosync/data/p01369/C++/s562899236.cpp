#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	int r,l,tx,ans=0,i;
	int ss[32];
	for(i=0;i<32;i++){
		ss[i]=0;
	}
	
	while(1){
		cin >> a;
		if(a=="#") break;
		tx=a.length();
		for(i=0;i<tx;i++){
			if(a[i]=='q') ss[i]=1;
			if(a[i]=='w') ss[i]=1;
			if(a[i]=='e') ss[i]=1;
			if(a[i]=='r') ss[i]=1;
			if(a[i]=='t') ss[i]=1;
			if(a[i]=='a') ss[i]=1;
			if(a[i]=='s') ss[i]=1;
			if(a[i]=='d') ss[i]=1;
			if(a[i]=='f') ss[i]=1;
			if(a[i]=='g') ss[i]=1;
			if(a[i]=='z') ss[i]=1;
			if(a[i]=='x') ss[i]=1;
			if(a[i]=='c') ss[i]=1;
			if(a[i]=='v') ss[i]=1;
			if(a[i]=='b') ss[i]=1;
		}
		for(i=0;i<tx-1;i++){
			if(ss[i]!=ss[i+1]) ans++;
		}
		cout << ans << endl;
		for(i=0;i<tx;i++){
			ss[i]=0;
		}
		ans=0;
	}
	return 0;
}