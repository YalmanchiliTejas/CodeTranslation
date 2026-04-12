#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<cassert>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
const long long MOD=1e9+7;
long long quipow(int i,long long x){
	long long res=1;
	while(i>0){
		if(i&1) res=res*x%MOD;
		x=x*x%MOD;
		i>>=1;
	}
	return res;
}
long long dp1[105],dp2[105],ndp1[105],ndp2[105];      //dp2[i]:到第i行为止依然有序的情况 
int h[105];
vector<int> v;
map<int,int> mp;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>h[i];
		v.push_back(h[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<v.size();i++) mp[v[i]]=i;
	for(int i=0;v[i]<=h[0]&&i<v.size();i++){
		dp2[i]=2*quipow(h[0]-v[i],2)%MOD;
		dp1[i]=(quipow(h[0],2)-dp2[i]+MOD)%MOD;
	}
	for(int i=1;i<n;i++){
		for(int j=0;v[j]<=min(h[i],h[i-1])&&j<v.size();j++) {
			ndp1[j]=dp1[j]%MOD;
			ndp2[j]=(dp2[j]+dp2[min(mp[h[i-1]],mp[h[i]])])%MOD;
			dp1[j]=ndp1[j]*quipow(h[i]-h[i-1],2)%MOD;
			dp2[j]=ndp2[j]*quipow(h[i]-h[i-1],2)%MOD;
		}
		int idx=mp[h[i-1]];
		if(h[i]>h[i-1]){
			for(int j=idx+1;v[j]<=h[i]&&j<v.size();j++){
				ndp1[j]=((ndp1[j-1]+ndp2[j-1])%MOD*quipow(v[j]-v[j-1],2)%MOD-ndp2[j-1]+MOD)%MOD;
				ndp2[j]=ndp2[j-1]%MOD;
				dp1[j]=ndp1[j]*quipow(h[i]-v[j],2)%MOD;
				dp2[j]=ndp2[j]*quipow(h[i]-v[j],2)%MOD;
			}
		}
	}
	long long res=0;
	res=(dp1[mp[h[n-1]]]+dp2[mp[h[n-1]]])%MOD;
	cout<<res;
}