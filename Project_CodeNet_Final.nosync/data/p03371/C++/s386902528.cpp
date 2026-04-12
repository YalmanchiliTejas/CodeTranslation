// Created by ...Lusifer
#include<bits/stdc++.h>
using namespace std;
 
#define pb 		push_back
#define mp 		make_pair
#define prior   priority_queue
#define MOD 	1000000007
#define INF64 	(long long)1e18
#define INF 	(int)1e9
#define PI 		3.1415926535897932384626433832795 
#define ll      long long
#define ld		long double
#define ret     return
#define NUM 	1000001
const int SIZE = 2e5+4;
void fastio(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void solveTest(){
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	ll sum1 = a*x+b*y;
	for(int i=1;i<=max(x,y);i++){
		ll sum2 = 2*i;
		ll sum3 = c*sum2+(a*max(0,x-i))+(b*max(0,y-i));
		sum1 = min(sum3,sum1);
	}
	cout<<sum1<<endl;
	return ;
}
 
int main(){
	fastio();

	int t=1;
	//cin>>t;
	while(t--){
		solveTest();
 
	}
	return 0;
}