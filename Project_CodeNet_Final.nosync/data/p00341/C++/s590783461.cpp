#include <bits/stdc++.h>
using namespace std;

int b[105];

int main(){
	int d,c=0;
	for(int i=0;i<12;i++){
		cin>>d;
		b[d-1]++;
	}
	for(int i=0;i<100;i++){
		if(b[i]==4) c+=1;
		if(b[i]==8) c+=2;
		if(b[i]==12) c+=3;
	}
	if(c==3) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
