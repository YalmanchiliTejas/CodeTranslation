#include <bits/stdc++.h>
using namespace std;

long long layers[51];
long long pat[51];
map<string, long long> M;

long long solve(long long a, long long b){
	//cout<<a<<" "<<b<<endl;
	
	if(b<=0){
		return 0;
	}else if(b==layers[a]){
		return pat[a];
	}else if(b>layers[a]){
		return pat[a]+1+solve(a, b-layers[a]-1);
	}else{
		return solve(a-1, b-1);
	}
}

int main(){
	pat[0]=1;
	layers[0]=1;
	for(int i=1;i<=50;i++){
		pat[i]=2*pat[i-1]+1;
		layers[i]=2*layers[i-1]+3;
	}
	long long n,x;
	cin>>n>>x;
	cout<<solve(n,x)<<endl;
	
}