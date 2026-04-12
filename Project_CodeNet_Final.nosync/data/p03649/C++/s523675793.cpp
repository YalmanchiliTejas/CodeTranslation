#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000010

bool check(vector<long long> &a,long long mid){
	long long cnt = 0;
	long long N = a.size();
	for(int i=0;i<a.size();i++){
		long long t = a[i] + mid - (N-1);
		if(t>0)cnt += (t+N)/(N+1);
	}
	if(cnt>mid)return false;
	else return true;
}

int main(){
	
	long long N;
	cin>>N;
	
	vector<long long> a(N);
	for(int i=0;i<N;i++)cin>>a[i];
	
	long long ok = Inf/50 + 1;
	long long ng = -1;
	
	while(ok-ng>1){
		long long mid = (ok+ng)/2;
		bool f = false;
		for(int i=0;i<50;i++){
			if(check(a,mid*50+i)){
				ok = mid;
				f=true;
				break;
			}
		}
		if(!f)ng = mid;
	}
	
	for(int i=0;i<50;i++){
		if(check(a,ok*50+i)){
			cout<<ok*50+i<<endl;
			return 0;
		}
	}
	
	//cout<<ok<<endl;
			
	
	return 0;
}