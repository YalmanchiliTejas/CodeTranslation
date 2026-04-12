#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000002



int main(){
	
	int N;
	cin>>N;
	
	vector<long long> a(N);
	for(int i=0;i<N;i++)cin>>a[i];
	
	long long ans = 0LL;
	
	for(int i=1;i<N;i++){
		long long temp = 0LL;
		int r = (N-1)-i;
		int l = i;
		set<int> S;
		while(true){
			if(S.count(l)||S.count(r))break;
			if(r-i<=0)break;
			if(l>=N-1)break;
			if(r==l)break;
			temp += a[l]+a[r];
			ans = max(ans,temp);
			S.insert(l);
			S.insert(r);
			l+=i;
			r-=i;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}