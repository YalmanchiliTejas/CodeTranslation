#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<long long> a(N);
	for(auto &i:a)cin >> i;
	long long ans=0;
	long long count;
	
	do{
		count=0;
		for(int i=0;i<N;i++){
			long long t=a[i]/N;
			count+=t;
			a[i]-=N*t;
			a[i]-=t;
		}
		for(int i=0;i<N;i++)a[i]+=count;
		ans+=count;
	}while(count>0);
	
	cout << ans << endl;
	return 0;
}