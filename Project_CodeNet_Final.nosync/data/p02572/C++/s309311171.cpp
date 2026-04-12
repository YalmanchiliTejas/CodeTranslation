#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define qi queue<int>
#define vi vector<int>
#define ll long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define prq priority_queue
#define foreach(it,c) for(__typeof((c).begin()) it=c.begin();it!=c.end();it++)
//#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
inline ll read(){
	ll x=0;
	int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	return x*f;
}
inline void out(int x){
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
const ll M=1e9+7;
int n;
ll a[202020],s=0,ans=0; 
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	cin>>n;
	fo(i,0,n)cin>>a[i],s+=a[i];
	fo(i,0,n)ans=(ans+(s-a[i])%M*a[i]%M)%M;
	if(ans%2==0)cout<<ans/2<<endl;
	else cout<<(ans+M)/2<<endl;
	return 0;
}
