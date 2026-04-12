#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int a[100],len,K;
long ans=0;
int solve(int k,int s){
	if(s==len)return 0;
	if(a[s]==0)return solve(k,s+1);
	if(k==1)return a[s]+9*(len-1-s);
	else if(k==2){
		return (len-1-s)*(len-2-s)/2*81
				+(len-1-s)*(a[s]-1)*9
				+solve(k-1,s+1);
	}else if(k==3){
		return (len-1-s)*(len-2-s)*(len-3-s)/6*729
				+(len-1-s)*(len-2-s)/2*81*(a[s]-1)
				+solve(k-1,s+1);
	}else return 0;
}
int main(){

	string S;
	cin>>S>>K;
	len=S.length();
	for(int i=0;i<len;i++)a[i]=S[i]-'0';
	
	cout<<solve(K,0);
	return 0;
}