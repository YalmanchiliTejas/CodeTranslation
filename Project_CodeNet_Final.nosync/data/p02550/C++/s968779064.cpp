
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  randomINIT     mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define  all(x)         (x).begin(),(x).end()
#define  mset(x,val)    memset(x,val,sizeof(x))
#define  endl           "\n"
#define  pb             push_back
#define  sym(s)         s="#"+s+"#";
#define  mp             make_pair
#define  s              second
#define  f              first
#define  dline          cerr<<"///REACHED///\n";
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());

typedef  long long             ll;
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   N  =  3e+5+7;

vll adj[N];ll vis[N]={};
int dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1};
int dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

//<<-----Declare Variable Here------->>//
int t=1;
ll n,x,m;
set<ll>set1,set2;
vll v;
//<<-----Implement Functions Here---->>//


//<<-----Start of Main--------------->>//
void MAIN(){
		cin>>n>>x>>m;ll ans = 0;
		ll f = 0;
		if(n<=1e8)
		{
			ll ans = 0;
			for(ll i=1;i<=n;i++)
			{
				if(x==0)break;
				ans += x%m;
				x = (x%m * x%m)%m;
			}
			cout<<ans<<endl;return;
		}
		ll count1 = 0;ll sum1 = 0;ll count2 = 0;ll sum2 = 0;
		for(ll i=1;i<=1e+5;i++)
		{
			ll h = x%m;
			if(set1.find(h)!=set1.end()){
				f = h;break;
			}
			set1.insert(h);sum1 += h;count1++;v.pb(h);
			x = (x%m * x%m)%m;
		}

		for(auto it:v){
			if(it==f)break;
			set2.insert(it);
			count2++;sum2+=it;
			count1--;sum1-=it;
		}
		ll pos = -1;
		for(ll i=0;i<=1e+5;i++)
		{
			if(v[i]==f){pos = i;break;}
		}
		
		n-=count2;ans += sum2;
		ans += n/count1*sum1;
		ll h = n%count1;
		for(ll i=pos;;i++){
			if(h==0)break;
			ans += v[i];h--;
		}
		cout<<ans<<endl;





		
}

int main(){
    fastio;randomINIT;
    
    while(t--){
        MAIN();
    }

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}