#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int t[100000];
int main(){
	int n;scanf("%d",&n);
	int Max=0;
	rep(i,n){
		scanf("%d",&t[i]);
		Max=max(Max,t[i]);
	}
	vector<int>v;
	for(int i=1;i*i<=Max;i++){
		if(Max%i==0){
			v.push_back(i);
			v.push_back(Max/i);
		}
	}
	sort(v.begin(),v.end());
	int cnt=0;
	rep(i,n){
		cnt+=*lower_bound(v.begin(),v.end(),t[i])-t[i];
	}
	cout<<cnt<<endl;
}