#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

long long kum[3002],arr[3002];
long long memo[3002][3002];

void createkum(int n){
	for(int i=1;i<=n;i++){
		kum[i]=kum[i-1]+arr[i];
	}
}

long long rangesum(int x,int y){
	return kum[y]-kum[x-1];
}

long long rek(int a,int b){
	if(a==b) return arr[a];
	if(memo[a][b]!=-1) return memo[a][b];
	memo[a][b]=max(arr[a]+rangesum(a+1,b)-rek(a+1,b),arr[b]+rangesum(a,b-1)-rek(a,b-1));
	return memo[a][b];
}

int main () {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	createkum(n);
	memset(memo,-1,sizeof memo);
	cout<<2*rek(1,n)-kum[n];



return 0;
}

