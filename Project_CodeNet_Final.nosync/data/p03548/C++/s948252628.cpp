#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<complex>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a-c<0)cout<<"0"<<endl;
	else cout<<(a-c)/(b+c)<<endl;
	return 0;
}
