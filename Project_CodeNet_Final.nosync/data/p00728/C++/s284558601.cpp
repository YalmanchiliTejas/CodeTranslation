#include<iostream>
using namespace std;
int main(){
	int n,m;
	int a,b,c;
	int i,j,k;
	int s=0;
	while(cin>>n){
		if(!n)break;
		b=0,c=1e5,s=0;
		for(i=0;i<n;i++){
			cin>>a;
			if(b<a)b=a;
			if(a<c)c=a;
			s+=a;
		}
		s-=b+c,n-=2;
		s/=n;
		cout<<s<<endl;
	}
}

