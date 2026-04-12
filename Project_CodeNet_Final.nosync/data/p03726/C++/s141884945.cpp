#include<bits/stdc++.h>				//edit by thidailoc
using namespace std;				//team three wolves
typedef long long ll;
typedef vector<ll> vi;
#define fu(i,a,b)   for(ll i=a;i<b;i++)
#define fd(i,b,a)   for(ll i=b;i>=a;i--)
#define pb(i)	    push_back(i)
#define popb()    	pop_back()
#define sc(a) 	    scanf("%lld",&a)
#define sc2(a,b)    scanf("%lld%lld",&a,&b)
#define pr(a)	    printf("%lld ",a)
#define pr2(a,b)    printf("%lld %lld",a,b)
#define lowb(a,n,x) lower_bound(a,a+n,x) -a
#define lowb2(a,x)	lower_bound(a.begin(),a.end(),x) -a.begin()
#define all(x) 		(x).begin(), (x).end()
#define sz(a) 		(ll)a.size()
#define le			length()						
#define re 			return 	
#define debug(x)    cerr << #x << " = " << x << endl
#define INPUT       freopen("locin.txt", "r", stdin)
#define OUTPUT      freopen("locout.txt", "w", stdout)

double const eps = 1e-6;	//dung trong sai so
ll const Base=1e9+7;
ll arr[100005],prevx[100005],siz[100005];
vi dske[100005];
ll Solves(){
	//INPUT;
	ll n,k,cnt=0,ans=0,x,u,v,cur;
	// PROCESSING IN HERE
	sc(n);
	if(n==1)re cout<<"First",0;
	
	fu(i,1,n){
		sc2(u,v);
		dske[u].pb(v);
		dske[v].pb(u);
	}
	queue<ll> qu;		//white pos
	fu(i,1,n+1){
		siz[i]=sz(dske[i]);
		if(sz(dske[i])==1)qu.push(dske[i][0]),prevx[dske[i][0]]=i;				
	}
	
	while(qu.size()){
		cur=qu.front(); qu.pop();
		if(arr[cur]==1 or arr[cur]==-1)continue;
		arr[cur]=1;				//white
		arr[prevx[cur]]=-1;		//black
		siz[prevx[cur]]=0;
		siz[cur]=0;

		fu(j,0,sz(dske[cur])){
			x=dske[cur][j];
			if(siz[x]){
				if(--siz[x]==1){
					fu(q,0,sz(dske[x])){
						if(arr[dske[x][q]]==0){
							qu.push(dske[x][q]);
							prevx[dske[x][q]]=x;
						}
					}
				}
			}
		}
		
	}
	fu(i,1,n+1){
		if(arr[i]!=-1){
			fu(j,0,sz(dske[i])){
				if(arr[dske[i][j]]==-1)break;
				if(j+1==sz(dske[i]))re cout<<"First",0;
			}
		}
	}
	
	cout<<"Second";
	re 0;
}


int main(){
	Solves();
}