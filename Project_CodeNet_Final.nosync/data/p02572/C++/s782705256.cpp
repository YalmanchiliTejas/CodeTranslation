#include <bits/stdc++.h>
using namespace std;

long long N,arr[200010],prefix[200010]; const long long MOD=1e9+7;

long long Sub(long long a, long long b){
	if(a>b)return a-b;
	return a+1000000007-b;
}

long long Add(long long a, long long b, long long c){
	long long currAdd=(b*c)%MOD;
	return (a+currAdd)%MOD;
}

void Input(){
	cin>>N;
	for(long long i=0; i<N; i++){
		cin>>arr[i];
		if(i==0){
			prefix[i]=arr[i];
		}else{
			prefix[i]=(prefix[i-1]+arr[i])%MOD;
		}
	}
}

void Solve(){
	long long total=0;
	for(long long i=0; i<N; i++){
		total=Add(total,arr[i],Sub(prefix[N-1],prefix[i]));
	}
	cout<<total<<'\n';
}

int main(){
	Input();
	Solve();
}