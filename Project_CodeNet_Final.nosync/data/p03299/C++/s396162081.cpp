#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

int beki(long long a,long long b,int M = modulo){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=((long long)x*a)%M;
		}
		a=((long long)a*a)%M;
		b>>=1;
	}
	return x;
}

pair<int,int> dfs(vector<int> h){
	int width = h.size();
	int m = 1000000004;
	for(int i=0;i<h.size();i++){
		m = min(m,h[i]);
	}
	int height = m;
	
	for(int i=0;i<h.size();i++){
		h[i] -= m;
	}
	
	int check = 1,notcheck = 1;
	bool f = false;
	int cnt0 = 0;
	while(h.size()!=0){
		while(h.size()!=0&&h.back()==0){
			h.pop_back();
			cnt0 ++;
		}
		if(h.size()==0)break;
		vector<int> t;
		while(h.size()!=0&&h.back()!=0){
			t.push_back(h.back());
			h.pop_back();
		}
		
		pair<int,int> p = dfs(t);
		if(!f){
			f=true;
		}
		check = mod(check * p.first);
		notcheck = mod(notcheck * mod(p.first*2 + p.second));
	}
	
	if(f){
		notcheck = mod(notcheck * beki(2,cnt0));
		check = mod(check * 2);
		notcheck = mod(notcheck - check);
		check = mod(check * beki(2,height-1));
	}
	else{
		check = beki(2,height);
		notcheck = mod(beki(2,width)-2);
	}
	//cout<<height<<','<<width<<','<<check<<','<<notcheck<<endl;
	return make_pair(check,notcheck);
}
	

int main(){
	
	int N;
	cin>>N;
	
	vector<int> h(N);
	for(int i=0;i<N;i++){
		cin>>h[i];
	}
	
	pair<int,int> p = dfs(h);
	
	cout<<mod(p.first+p.second)<<endl;
	
	return 0;
}
