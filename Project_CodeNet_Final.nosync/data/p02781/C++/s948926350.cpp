//~#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//~#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//~#pragma GCC target("avx2")  //Enable AVX
#include<bits/stdc++.h>
using namespace std;
#define int ll
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
const int mod=1e9+7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int mul(int a,int b)
{
	return ((a)*1ll*(b))%mod;
}
 
void add(int &a,int b)
{
	a+=b;
	if(a>=mod)a-=mod;
}
 
int sub(int a,int b){
	a-=b;
	if(a<0){
		a+=mod;
	}
	return a;
}
 
int powz(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1){
			res=mul(res,a);
		}
		b/=2;
		a=mul(a,a);
	}
	return res;
}
 
template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
	input>>x.F>>x.S;
	return input;
}
 
template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
	for(auto& i:x)
		input>>i;
	return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
	for(auto& i:x)
		output<<i<<' ';
	return output;
}
 
const int N=1000002;

int t[4*N];


int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(sum(v*2, tl, tm, l, min(r, tm))
           ,sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2] , t[v*2+1]);
    }
}


void solve(){
	string n;
	cin>>n;
	int k;
	cin>>k;
	int vv=n.length();
	for(int i=0;i<n.length();i++){
		update(1,0,vv-1,i,n[i]-'0');
	}	
	ll ans=0;
	if(k==3){
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				for(int kk=1;kk<=9;kk++){
					for(int left=0;left<vv;left++){
						if((sum(1,0,vv-1,0,left-1)>0)||(n[left]>(i+'0'))){
							ans+=((vv-left-1)*1LL*(vv-left-2))/2;
							continue;
						}
						if(n[left]!=(i+'0')){
							continue;
						}
						for(int left2=left+1;left2<vv;left2++){
							if((sum(1,0,vv-1,left+1,left2-1)>0)||(n[left2]>(j+'0'))){
								ans+=((vv-left2-1));
								continue;
							}
							if(n[left2]!=(j+'0')){
								continue;
							}
							for(int left3=left2+1;left3<vv;left3++){
								if((sum(1,0,vv-1,left2+1,left3-1)>0)||(n[left3]>(kk+'0'))){
									ans++;
									continue;
								}
								if(n[left3]!=(kk+'0')){
									continue;
								}
								ans++;							
							}
						}
					}
				}
			}
		}
	}
	else if(k==2){
			for(int j=1;j<=9;j++){
				for(int kk=1;kk<=9;kk++){
					for(int left2=0;left2<vv;left2++){
						if((sum(1,0,vv-1,0,left2-1)>0)||(n[left2]>(j+'0'))){
							ans+=((vv-left2-1));
							continue;
						}
						if(n[left2]!=(j+'0')){
							continue;
						}
						for(int left3=left2+1;left3<vv;left3++){
							if((sum(1,0,vv-1,left2+1,left3-1)>0)||(n[left3]>(kk+'0'))){
								ans++;
								continue;
							}
							if(n[left3]!=(kk+'0')){
								continue;
							}
							ans++;							
						}
					}
				}
			}
	}
	else{
		for(int i=1;i<=9;i++){
			for(int j=0;j<vv;j++){
				if(sum(1,0,vv-1,0,j-1)>0||(n[j]>(i+'0'))){
					ans++;
					continue;
				}
				if(n[j]!=(i+'0')){
					continue;
				}
				ans++;
			}
		}
	}
	cout<<ans;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	//~cin>>tc;
	for(int _=0;_<tc;_++){
		//~ cout<<"Case #"<<_+1<<": ";
		solve();
		if(_!=tc-1)
		cout<<"\n";
	}
}
