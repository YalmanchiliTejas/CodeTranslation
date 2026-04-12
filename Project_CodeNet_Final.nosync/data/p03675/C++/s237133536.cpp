#include "bits/stdc++.h"
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
const int M=100010;
int INF=1000000007;
using ll=long long;

int main(){
	int n;
	string a[200010],t="";

	cin>>n;
	rep(i,0,n)cin>>a[i];
	if(n==1){
		cout<<a[0]<<endl;
		return 0;
	}
	if(n%2==0){
		for(int i=n-1;i>0;i-=2)t+=a[i]+" ";
		for(int i=0;i<n;i+=2){
			t+=a[i]+" ";
		}
		cout<<t<<endl;
		return 0;
	}else{
		for(int i=n-1;i>=0;i-=2)t+=a[i]+" ";
		for(int i=1;i<n;i+=2){
			t+=a[i]+" ";
		}
		cout<<t<<endl;
		return 0;
	}
}
