#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin>>n;
	m=15;
	k=0;
	while(m<=n){
		m+=15;
		k++;
	}
	cout<<800*n-200*k<<endl;
}