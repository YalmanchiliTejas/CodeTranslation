#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
 
using namespace std;
vector<long long int> ss;
vector<long long int> memo[100005];
vector<long long int> memo2[100005];
 
 
int main() {
	// your code goes here
	int n;
	int U;
	cin>>n;
	memset(memo,0,sizeof(memo));
	memset(memo2,0,sizeof(memo2));
	for(int i=0;i<n;i++){
		long long int s;
		cin>>s;
		ss.push_back(s);
	}
	for(int i=1;i<n;i++){
		for(int k=1;(k*k)<=i;k++){
			if(i%k>0)continue;
			int p=k;
			int s1=memo[p].size();
			if(s1>0){
				memo[p].push_back(ss[i]+memo[p][s1-1]);
			}else{
				memo[p].push_back(ss[i]);
			}
			if(k*k==i)continue;
			p=i/k;
			s1=memo[p].size();
			if(s1>0){
				memo[p].push_back(ss[i]+memo[p][s1-1]);
			}else{
				memo[p].push_back(ss[i]);
			}
		}
	}
	std:reverse(ss.begin(),ss.end());
	for(int i=1;i<n;i++){
		for(int k=1;(k*k)<=i;k++){
			if(i%k>0)continue;
			int p=k;
			int s1=memo2[p].size();
			if(s1>0){
				memo2[p].push_back(ss[i]+memo2[p][s1-1]);
			}else{
				memo2[p].push_back(ss[i]);
			}
			if(k*k==i)continue;
			p=i/k;
			s1=memo2[p].size();
			if(s1>0){
				memo2[p].push_back(ss[i]+memo2[p][s1-1]);
			}else{
				memo2[p].push_back(ss[i]);
			}
		}
	}
	long long int ans=0;
	int count1=0;
	U=n-1;
	//U=50000;
	for(int a=2;a<U;a++){
		int r=U-a;
		for(int k=1;k*k<=r;k++){
			int b=(a-r/k);
			if(r%k==0 && b<a && b>0){
				int c=a-b;
				int t=(U-a)/c-1;
				if(t<0 || memo[c].size()<=t || memo2[c].size()<=t || (U-a)%c!=0 || ((a%c==0)&&(a/c)<=(U-a)/c)){
					//何もしない
				}else{
					long long int sum=memo[c][t]+memo2[c][t];
					//cout<<sum<<" "<<a<<" "<<b<<"\n";
					if(ans<sum)ans=sum;
				}
			}
			b=(a-k);
			if(r%k==0 && b<a && b>0){
				int c=a-b;
				int t=(U-a)/c-1;
				if(t<0)continue;
				if(memo[c].size()<=t)continue;
				if(memo2[c].size()<=t)continue;
				if((U-a)%c!=0)continue;
				if((a%c==0)&&(a/c)<=(U-a)/c)continue;
				long long int sum=memo[c][t]+memo2[c][t];
				//cout<<sum<<" "<<a<<" "<<b<<"\n";
				if(ans<sum)ans=sum;
			}
		}
	}
	cout<<ans;
	return 0;
}