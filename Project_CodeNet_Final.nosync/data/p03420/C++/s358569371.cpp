#include<iostream>
using namespace std;
int main(){
	int n,m;
	int i,j,k;
	int a,b;
	long long int s=0;
	cin>>n>>m;
	for(i=m+1;i<=n;i++){
		a=n/i,b=n%i;
		s+=a*(i-m);
		if(b>=m){
			s+=b-m;
			if(m!=0)s++;
		}
	}
	cout<<s<<endl;
	return 0;
}
