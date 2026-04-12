#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#define lol(i,n) for(ll i=0;i<n;i++)
#define mod 1000000007
#define mul(a,b) a=(a*b)%mod;
typedef long long ll;

using namespace std;
ll po(ll x){
    ll res=1;
    for(ll y=2;x;x>>=1,y=y*y%mod){
	if(x&1)res=res*y%mod;
    }
    return res;
}
ll mo(ll x){
    x%=mod;
    if(x<0)x+=mod;
    return x;
}
typedef pair<ll,ll> P;
#define N 110
vector<ll> v[N];
ll n,f[N],g[N],l[N],r[N],w[N],u[N],h[N],m;
ll ans;
void func(ll x){
    ll len=r[x]-l[x]-1;
    if(len==1){
	mul(ans,po(w[x]));
	f[x]=g[x]=0;
	return;
    }
    ll fm=1,gm=1,sum=0;
    for(auto c:v[x]){
	func(c);
	if(r[c]-l[c]-1==1)continue;
	sum+=r[c]-l[c]-1;
	fm=mo(fm*f[c]);
	gm=mo(gm*(2*f[c]+g[c]));
    }
    if(sum==0){
	f[x]=mo(po(w[x]));
	g[x]=mo(po(len)-2);
	return;
    }
    f[x]=mo(fm*po(w[x]));
    g[x]=mo(gm*po(len-sum));
    g[x]=mo(g[x]-2*fm);
}
int main(){
    cin>>n;
    if(n==1){
	cin>>n;
	cout<<po(n)<<endl;
	return 0;
    }
    lol(i,n)cin>>h[i];
    unordered_map<ll,vector<ll> >mas;
    lol(i,n){
	mas[h[i]].push_back(i);
    }
    sort(h,h+n);
    set<ll> st; st.insert(-1); st.insert(n);
    m=1,l[0]=-1,r[0]=n,w[0]=u[0]=h[0];
    lol(i,n){
	if(i&&h[i-1]==h[i])continue;
	for(auto x:mas[h[i]]){
	    auto il=st.lower_bound(x); il--;
	    ll L=*il;
	    auto ir=st.upper_bound(x);
	    ll R=*ir;
	    if(l[m-1]==L&&r[m-1]==R)continue;
	    l[m]=L,r[m]=R,u[m]=w[m]=h[i],m++;
	}
	for(auto x:mas[h[i]])st.insert(x);
    }
    lol(i,m){
	for(ll j=i-1;~j;j--){
	    if(l[j]<=l[i]&&r[i]<=r[j]){
		v[j].push_back(i);
		w[i]=u[i]-u[j];
		break;
	    }
	}
    }
    ans=1;
    func(0);
    cout<<mo(ans*(f[0]+g[0]))<<endl;
    return 0;
}
