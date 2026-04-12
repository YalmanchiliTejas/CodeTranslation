#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int main(){
	int N;
	long long X;
	cin >> N >> X;

	vector<pair<long long,long long>> size_Psize(N+1);
	size_Psize.at(0)=make_pair(1,1);
	for(int i=1;i<=N;i++){
		size_Psize.at(i).first=(size_Psize.at(i-1).first)*2 +3;
		size_Psize.at(i).second=(size_Psize.at(i-1).second)*2 +1;
	}
	long long ans=0;
	int now=N;
	while(X>0){
		if(X>=size_Psize.at(now).first){
			ans+=size_Psize.at(now).second;
			X-=size_Psize.at(now).first;

			if(X>0){
				ans++;
				X--;
			}
		}
		else{
			X--;
			now--;
		}
	}
	cout << ans << endl;

	return 0;
}
