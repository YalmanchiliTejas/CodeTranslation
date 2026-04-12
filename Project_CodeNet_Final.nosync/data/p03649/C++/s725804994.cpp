#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>//"geometry.cpp"
using namespace std;
#define pb push_back//Can be used for STRING
#define fi first
#define sc second
#define mp make_pair
#define is insert
typedef pair<int,int> pii;//Add other types in the same way.

#define MAX_N 50

long long n,a[MAX_N];

bool calc(int i){
	bool ret=true;
	for(int j=0;j<n;++j) if(i!=j){
		a[j]+=a[i]/n;
		if(a[j]>=n) ret=false;
	}
	a[i]%=n;
	return ret;
}

int main(){
	cin>>n;
	long long ans=0;
	for(int i=0;i<n;++i){
		cin>>a[i];
		ans+=a[i];
	}
	for(int i=0;;++i) if(calc(i%n)) break;
	for(int i=0;i<n;++i) ans-=a[i];
	cout<<ans<<endl;
}