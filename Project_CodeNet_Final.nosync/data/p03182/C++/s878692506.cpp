#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> vals[200005],segment;
long long n,m,t,sum;

long long getmin(int a , int b , int curr , int l , int r){
	if(b < l || a > r){
		return 1000000000;
	}
	if(a <= l && b >= r){
		return segment[curr].first+segment[curr].second;
	}
	segment[2*curr].second += segment[curr].second;
	segment[2*curr+1].second += segment[curr].second;
	segment[curr].first += segment[curr].second;
	segment[curr].second = 0;
	int mid = (l+r)/2;
	long long ret = min(getmin(a,b,2*curr,l,mid),getmin(a,b,2*curr+1,mid+1,r));
	segment[curr].first = min(segment[2*curr].first+segment[2*curr].second,segment[2*curr+1].first+segment[2*curr+1].second);
	return ret;
}

void update(int a , int b , long long val , int curr , int l , int r){
	if(b < l || a > r){
		return ;
	}
	if(a <= l && b >= r){
		segment[curr].second += val;
		return ;
	}
	segment[2*curr].second += segment[curr].second;
	segment[2*curr+1].second += segment[curr].second;
	segment[curr].first += segment[curr].second;
	segment[curr].second = 0;
	int mid = (l+r)/2;
	update(a,b,val,2*curr,l,mid),update(a,b,val,2*curr+1,mid+1,r);
	segment[curr].first = min(segment[2*curr].first+segment[2*curr].second,segment[2*curr+1].first+segment[2*curr+1].second);
}

int main(){
	cin >> n >> m;
	t = pow(2,ceil(log2(n+2)));
	segment.resize(2*t,{0,0});
	for(int i = 0 ; i < m ; i += 1){
		int l,r,v;
		cin >> l >> r >> v;
		vals[l].push_back({r,v});
		sum += v;
	}
	for(int i = n ; i >= 0 ; i -= 1){
		update(i+1,i+1,getmin(i+2,t,1,1,t),1,1,t);
		for(pair<int,int> j : vals[i]){
			update(j.first+2,t,j.second,1,1,t);
		}
	}
	cout << sum-getmin(1,1,1,1,t) << endl;
}