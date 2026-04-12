#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,a,b,c,x;
	int y[10000];
	while(cin>>n>>a>>b>>c>>x,n|a|b|c|x){
		for(int i=0;i<n;i++)cin>>y[i];
		int f=0;
		for(int i=0;i<n&&f<=10000;i++){
			while(x!=y[i] && f<=10000){
				x=(a*x+b)%c;
				f++;
			}
			if(i+1<n && f<=10000){
				x=(a*x+b)%c;
				f++;
			}
		}
		cout<<(f<=10000?f:-1)<<endl;
	}
	return 0;
}