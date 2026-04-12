#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, ll> P;
const int MAX_N=1<<18;
const ll INF=1e18;
ll mx[2*MAX_N-1], part[2*MAX_N-1];
bool mada[2*MAX_N-1];
int m0;
void init(int n){
    m0=1;
    while(m0<n) m0*=2;
}

void eval(int k, int l, int r){
    if(mada[k]){
        mx[k]+=part[k];
        if(k<m0-1){
            part[2*k+1]+=part[k];
            part[2*k+2]+=part[k];
			mada[2*k+1]=1; mada[2*k+2]=1;
        }
        mada[k]=0;
        part[k]=0;
    }
}

void add(int a, int b, ll x, int k, int l, int r){
    eval(k, l, r);
    if(r<=a || b<=l) return;
    if(a<=l && r<=b){
        part[k]=x;
        mada[k]=1;
        eval(k, l, r);
    }else{
        add(a, b, x, k*2+1, l, (l+r)/2);
        add(a, b, x, k*2+2, (l+r)/2, r);
        mx[k]=max(mx[2*k+1], mx[2*k+2]);
    }
}
     
ll find(int a, int b, int k, int l, int r){
    eval(k, l, r);
    if(b<=l || r<=a){
        return -INF;
    }
    if(a<=l && r<=b){
        return mx[k];
    }else{
        return max(find(a, b, 2*k+1, l, (l+r)/2), find(a, b, 2*k+2, (l+r)/2, r));
    }
}
int main()
{
	int n, m;
	cin>>n>>m;
	ll sum=0;
	vector<P> v[200001];
	for(int i=0; i<m; i++){
		int l, r; ll a;
		cin>>l>>r>>a;
		sum+=a;
		v[r].push_back(P(l, -a));
	}
	ll dp=0; ll ans=0;
	init(n+2);
	for(int i=1; i<=n+1; i++){
		for(auto p:v[i-1]) add(0, p.first, p.second, 0, 0, m0);
		dp=max(dp, find(0, i-1, 0, 0, m0)); ans=max(ans, dp);
		add(i, i+1, dp, 0, 0, m0);
	}
	cout<<sum+ans<<endl;
	return 0;
}