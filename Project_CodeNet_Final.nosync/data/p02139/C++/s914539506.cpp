#include <iostream>
using namespace std;
int main() {
	int n,q,p=1,c,x;
	cin>>n>>q;
	for(int i=0;i<q;i++){
		cin>>c>>x;
		if(!c)cout<<((p+x-1)%n==0? n:(p+x-1)%n)<<endl;
		else {p=(p+x)%n; if(p==0)p=n;}
	}
	return 0;
}
