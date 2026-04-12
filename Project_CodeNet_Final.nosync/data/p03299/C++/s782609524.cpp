#include<iostream>
#define int long long
using namespace std;
const int N=102;
const int mod=1e9+7;
int ar[N];
int binpow(int x,int y){
	int tich=1;
	while(y){
		if(y&1){
			tich*=x;
			tich%=mod;
		}
		x*=x;
		x%=mod;
		y>>=1;
	}
	return tich;
}
pair<int,int> solve(int l,int r){
//	cout<<l<<' '<<r<<endl;
	int i,dem=0,num1=1,num2=1,min1=mod,lst=l;
	pair<int,int> tmp;
	for(i=l;i<=r;i++){
		min1=min(min1,ar[i]);
	}
	for(i=l;i<=r;i++){
		ar[i]-=min1;
	}
	for(i=l;i<=r;i++){
		if(!ar[i]){
			dem++;
			if(lst!=i){
				tmp=solve(lst,i-1);
				num1*=tmp.first;
				num1%=mod;
				num2*=(tmp.first+tmp.second);
				num2%=mod;
			}
			lst=i+1;
		}
//		dem++;
	}
	if(lst!=r+1&&lst!=l){
		tmp=solve(lst,r);
		num1*=tmp.first;
		num1%=mod;
		num2*=(tmp.first+tmp.second);
		num2%=mod;
	}
	num2=(binpow(2,dem)*num2+(binpow(2,min1)-2)*num1)%mod;
	if(num2<0){
		num2+=mod;
	}
	num1*=binpow(2,min1);
	num1%=mod;
	return {num1,num2};
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ar[i];
	}
	cout<<solve(1,n).second;
}
