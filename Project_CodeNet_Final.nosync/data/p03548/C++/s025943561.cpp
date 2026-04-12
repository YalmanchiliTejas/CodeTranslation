#include<iostream>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int a=(n-2*k);
	int b=a/m;
	for(int i=b;i>0;i--){
		if((m*i)+(k*(i-1))<=a){
			cout<<i;
			return 0;
		}
		
	}
	return 0;
} 