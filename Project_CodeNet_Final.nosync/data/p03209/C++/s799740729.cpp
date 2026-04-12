#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
 
#define DEBUG 0
 
#define lli long long unsigned int
#define REP(i,n) for(int i=0;i<n;i++)
 
using namespace std;

vector<lli> a,b,p;

lli calc(lli level,lli num){
	lli right = 0;
	lli left = a[level]-1;
	lli middle = (right+left)/2;
	if(DEBUG)cout<<"level="<<level<<" num= "<<num<<endl;

	if(level == 0)return 1;

	if(num == 0)return 0;
	else if(num < middle){
		return calc(level-1,num-1);
	}
	else if(num == middle){
		return p[level-1] + 1;
	}
	else if(middle < num){
		return p[level-1] + 1 + calc(level-1,num-middle-1);
	}
	else{
		return p[level];
	}
}


int main(){

	lli n,x;
	cin>>n>>x;
	a.resize(n+1);
	b.resize(n+1);
	p.resize(n+1);
	a[0] = 1;
	b[0] = 0;
	p[0] = 1;
	lli d = 2;
	for(lli i=1;i<=n;i++){
		b[i] = b[i-1] + d;
		p[i] = p[i-1] + d;
		a[i] = b[i]+p[i];
		d *= 2;
	}

	cout<<calc(n,x-1)<<endl;

	return 0;
}