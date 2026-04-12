#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N,X,M,arr[100100],sum=0,polasum=0,polasize=0,sisasum=0;
vector<ll> v(1,0);

ll f(long long a){
	return a*a%M;
}

void Input(){
	cin>>N>>X>>M;
}

void Solve(){
	for(long long i=1; i<=min(N,M); i++){
		if(arr[X]==0){
			arr[X]=i; v.push_back(X);
			sum+=X;
		}else{
			for(long long j=arr[X]; j<v.size(); j++){
				polasum+=v[j]; polasize++; 
			}
			break;
		}
		X=f(X);
	}
	if(polasum==0){
		cout<<sum<<'\n';
	}else{
		ll size=v.size()-1;
		ll sisa=(N-size)%polasize;
		for(long long j=arr[X]; j<sisa+arr[X]; j++){
			sisasum+=v[j];
		}
		cout<<sum+(N-size)/polasize*polasum+sisasum<<'\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solve();
}