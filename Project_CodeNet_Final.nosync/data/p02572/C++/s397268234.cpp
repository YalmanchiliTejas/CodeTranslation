#include<bits/stdc++.h>
using namespace std;
typedef long long L;
const int N=2e5+11,p=1e9+7;

int main(){
	int t=0,u=0;
	int i,x,n;
	cin>>n;
	while(n--){
		cin>>x;
		u=(u+(L)x*t)%p;
		t=(t+x)%p;
	}
	cout<<u<<endl;
}