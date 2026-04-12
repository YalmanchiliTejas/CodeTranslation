#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define MAX 1000000007
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
vector<ll> work(1);

void func(ll val,int l, int r){
	//fprintf(stderr,"l=%d, r=%d",l,r);
	if(r-l == 1){
		work[r]=val;
		return;
	}
	if(work[(l+r)/2] >= val)func(val,(l+r)/2,r);
	else func(val,l,(l+r)/2);
}

int main(void){
	int n;
	cin>>n;
	
	cin>>work[0];

	rep(i,n-1){
		ll tmp;
		cin>>tmp;
		if(work.size()==1){
			if(work[0] < tmp)work[0]=tmp;
			else work.push_back(tmp);
			continue;
		}
		if(work[work.size()-1] >= tmp)work.push_back(tmp);
		else if(work[0] < tmp)work[0]=tmp;
		else func(tmp,0,work.size()-1);
	}

	cout<<work.size()<<endl;
	return 0;
}
