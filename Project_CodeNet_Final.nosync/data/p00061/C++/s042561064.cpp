#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int pt[100],pn[101];
int main(){
	int a,b;
	char z;
	int top=0;
	while(true){
		cin>>a>>z>>b;
		if(a==0&&b==0)
			break;
		pn[a]=b;
		bool t=true;
		for(int i=0;i<top;i++)
			if(pt[i]==b)t=false;
		if(t==true){
			pt[top]=b;
			top++;
		}
	}
	sort(pt,pt+top);
	int c;
	while(cin>>c){
		int ans=0;
		while(true){
			if(pt[ans]==pn[c])
				break;
			ans++;
		}
		cout<<top-ans<<endl;
	}
	return 0;
}