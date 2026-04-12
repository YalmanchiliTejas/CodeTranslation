#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
	int a,b,ab,na,nb;cin>>a>>b>>ab>>na>>nb;
	int ans1,ans2,ans3;
	ans1 = a*na+b*nb;
	ans2 = nb*2*ab+max(0LL,na-nb)*a;
	ans3 = na*2*ab+max(0LL,nb-na)*b;
	//cout<<ans1<<" "<<ans2<<" "<<ans3<<" ";
	cout<<min({ans1,ans2,ans3});
}
