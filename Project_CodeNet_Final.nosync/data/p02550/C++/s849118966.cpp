#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int expo(int x,int y,int p){
    int a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}
int cnt=0;
int pow2(int x,int y,int p){
	if(y<=32){
		return expo(x,(1LL<<y),p);
	}
	else{
		int y2=expo(2,y,cnt)+cnt;
		return expo(x,y2,p);
	}
}


int solve(){
 	int n,x,m;cin>>n>>x>>m;
 	for(int i=1;i<=m;i++){
 		if(gcd(i,m)==1)cnt++;
 	}
 	map<int,int>mp;
 	vector<int>pre={0};
 	auto func=[&](int n){
 		return pow2(x,n-1,m);
 	};
 	int j=0;
 	int s=0;
 	int kk=0;
 	for(int i=1;i<=n;i++){
 		int val=func(i);
 		if(mp.count(val)){
 			j=mp[val];
 			s=pre[j-1];
 			int cyc=i-j;
 			int val=pre[i-1]-pre[j-1];
 			int g=(n-j+1)/(i-j);
 			s=s+val*g;
 			int z=j+g*(i-j);
 			for(z;z<=n;z++){
 				s+=func(z);
 			}
 			cout<<s<<endl;return 0;
 		}
 		mp[val]=i;
 		pre.pb(pre[i-1]+val);
 	}
	cout<<pre[n]<<endl;	 	
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
 