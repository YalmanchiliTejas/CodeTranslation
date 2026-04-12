#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int Mod=1e9+7;
long long a[N],b[N],s;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n-1;i>=1;i--)b[i]=(b[i+1]+a[i+1])%Mod;
	for(int i=1;i<=n-1;i++)s=((s%Mod)+(a[i]*b[i]%Mod))%Mod;
	cout<<s<<endl;
}