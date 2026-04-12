#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<iomanip>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
	double a,b;
	cin>>a>>b;
	cout<<fixed<<setprecision(10)<<1/(1/a+1/b)<<endl;
	return 0;
}
