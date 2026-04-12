#include <bits/stdc++.h> 
#define PB push_back
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<long long> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i]+(i>0?b[i-1]:0ll);
	}
	long long s=0ll;
	for(int i=0;i<n;i++){
		s+=(a[i]*((b[n-1]-b[i])%1000000007ll))%1000000007ll;
		s=s%1000000007;
	}
	cout<<s<<endl;
}
