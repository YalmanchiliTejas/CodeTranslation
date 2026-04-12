#include<bits/stdc++.h>

using namespace std;

long long binom(long long a,long long b){
	long long res=1;
	if(a<b) return 0;
	for(int i=0;i<b;i++){
		res*=(a-i);
		res/=(i+1);
	}
	return res;
}
long long sol(string &str,int i,int k){
	int n=str.size();
	if(i==n){
		if(k==0) return 1;
		return 0;
	}
	if(k==0) return 1;
	if(str[i]=='0') return sol(str,i+1,k);
	
	long long ch=str[i]-'0';
	long long res=binom(n-i-1,k-1)*(ch-1);
	for(int j=1;j<k;j++) res*=9;
	res+=sol(str,i+1,k-1);//ch
	long long res2=binom(n-i-1,k);//0
	for(int j=0;j<k;j++) res2*=9;
	res+=res2;
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	int k;
	cin >> k;
	
	int n=s.size();
	
	cout << sol(s,0,k) << "\n";
	return 0;
}