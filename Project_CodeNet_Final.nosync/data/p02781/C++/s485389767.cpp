#include<bits/stdc++.h>
using namespace std;
int f(int n,int k){
	if(k>n) return 0;
	if(k==0) return 1;
	if(k==1) return n;
	if(k==2) return n*(n-1)/2;
	if(k==3) return n*(n-1)*(n-2)/6;
}
int tenth(int k){
	int ret = 1;
	for(int i=0; i<k; i++) ret*=9;
	return ret; 
}
int main(){
	string s;
	int k;
	cin>>s>>k;
	vector<int>arr(s.length()+1,0);
	int n = s.length();
	for(int i=0; s[i]; i++){
		arr[i+1] = (int)(s[i]-'0');
	}
	int ret = 0;
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<arr[i]; j++){
			if(j==0) ret+=tenth(k)*f(n-i,k);
			else ret+=tenth(k-1)*f(n-i,k-1);
		}
		if(arr[i]) k--;
		if(k==0){
			ret++;
			break;
		}	
	}
	cout<<ret;
}