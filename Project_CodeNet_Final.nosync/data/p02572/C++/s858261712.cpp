#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof a) ;
typedef pair<int,int> pii ;
#define vi vector<int>
#define vit vector<int> :: iterator 
#define all(ans) ans.begin(),ans.end()
//#define sz(a) int(a.size())
#define ub upper_bound
#define lb lower_bound
#define create(Name,N,M,val) vector<vector<int> > Name(N,vector<int>(M,val))
#define ull unsigned long long
#define ll long long 
#define db double 
#define ldb long double
#define fl float
#define rep(i,a,b) for(int i=a;i<b;i++)
#define lrep(i,a,b) for(ll i=a;i<b;i++)
//#define all(c) c.begin(),c.end()
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define mpr make_pair
#define pb push_back
#define fr first
#define sn second
#define bpp(x) __builtin_popcountll(x)
const db PI = 3.141592653589793238462643383;
const long long INF = 1e9+7;
const long long mod = 998244353;
int getID(char c)
{
	if(c == ' ') return 0;
	return c - 'a' + 1 ;
}
/*
bool ok(string &s ,int l ,int r)
{
while(s[l]==s[r]) l++,r--;
return l>=r; 
}
int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,97,101,103};
int gcd(int a, int b)
{
while(b)
{
a%=b;
swap(a,b);
}
return a;
}
ll pw(ll a,ll b)
{
ll res=1;
while(b)
{
if(b&1) res=(res*a)%INF;
a=(a*a)%INF;
b>>=1;
}
return res;
}
bool isFib(int n)
{
int x,y;
x=sqrt(5*n*n+4); y=sqrt(5*n*n-4);
return ((x*x)==(5*n*n+4))||((y*y)==(5*n*n-4));
}
int ExtU(int a,int b,int &x,int &y)
{
if(a==0)
{
x=0; y=1; return b;
}
int x1,y1;
int d=ExtU(b%a,a,x1,y1);
x=y1-(b/a)*x1;
y=x1;
return d;
}
ll factors(ll n)
{
ll ct=0ll;
for(ll i=1ll;i*i<=n;i++)
{
if(n%i==0)
{
if(i*i==n)
ct++;
else
ct+=2ll;
}
return ct;
}
} 
vector<int>factorize(int n)
{
vi ans;
while(n%2==0)
{
ans.pb(2); n/=2;
}
for(int i=3;i<=sqrt(n);i+=2)
{
while(n%i==0)
{
ans.pb(i); n/=i;
}
}
if(n>2)
ans.pb(n);
return ans;
}
int mnpr[500003]={0};
void sprime(int n)
{
for(int i=2;i*i<=n;i++)
{
if(mnpr[i]==0)
{
for(int j=i*i;j<=n;j+=i)
{
if(mnpr[j]==0)
mnpr[j]=i;
}
}
}
for(int i=1;i<=n;i++)
if(mnpr[i]==0)
mnpr[i]=i;
}
int mxpr(int n)
{
int mx; 
while(n&1==0)
{
mx=2; n>>=1;
}
for(int i=3;i*i<=n;i+=2)
{
while(n%i==0)
{
mx=i; n/=i;
}
}
if(n>2)
mx=n;
return mx;
}
bool seg[100005]={true};
void ss(int r,int l)
{
rep(i,0,r-l+2)
seg[i]=true;
for(int i=2;i*i<=r;i++)
{
for(int j=max(i*i,((l+i-1)/i)*i);j<=r;j+=i)
seg[j-l]=false;
}
}
int phi(int n)
{
int res=n;
for(int i=2;i*i<=n;i++)
{
if(n%i==0)
{
while(n%i==0)
n/=i;
res-=res/i;
}
}
if(n>1)
res-=res/n;
return res;
}
int ncr(int n,int r)
{
int C[r+1];
mem(C,0);
C[0]=1;
for(int i=1;i<=n;i++)
{
for(int j=min(i,r);j;j--)
{
C[j]=(C[j]+C[j-1])%INF;
}
}
return C[r];
}
int bitzero(int n)
{
int ct=0;
while(n)
{
ct+=!(n&1);
n>>=1;
}
return ct;
}
string twocom(string &s)
{
int i;
for(i=s.length()-1;i>=0;i--)
if(s[i]=='1')
break;
if(i==-1)
{
return '1'+s;
}
for(int k=i-1;k>=0;k--)
{
if(s[k]=='1')
s[k]='0';
else
s[k]='1';
}
return s;
}
void sl()
{
int n;
goto e;
cin>>n;
e:
;
cout<<n;
return ;
}
*/
/*
void solv()
{
string s; cin>>s;
reverse(all(s));
int a[s.size()+1];
a[0]=0;
int ct[2019]={0};
ct[0]=1;
int ml=1;
rep(i,0,s.size())
{
a[i+1]=(a[i]+(s[i-1]-'0')*ml)%2019;
ml=10*ml % 2019;
ct[a[i+1]]++;
}
int ans=0;
rep(i,0,2019)
{
int x=ct[i]*(ct[i]-1)/2;
ans+=x;
}
cout<<ans;
return ;
}
*/
/*
struct sg
{
int st,end;
};
struct cmp
{
	bool operator () ( sg a, sg b )
	{
	int l1=a.end-a.st+1;
	int l2=b.end-b.st+1;
	return (l1<l2)||(l1==l2 && (a.st>b.st) );
	}
};

auto compare = [&](auto a, auto b){
return a.first<b.first || (a.first==b.first && a.second<b.second);
};
sort(bridges.begin(), bridges.end(), compare);

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
*/
/*
int n,m,curtime=0; 
vi v[15];
bool vis[15] ;
int par[15] , dis[15] , arp[15] , lw[15];
vi brg[15];
void ini()
{
	curtime=0;
	rep(i,1,n+1)
	{
	v[i].clear();
	vis[i]=0;
	arp[i]=0;
	dis[i]=0;
	par[i]=-1;
	lw[i]=1e8;
	}
}
void dfs(int u) // Bridges and Articulation points
{
	vis[u]=1; dis[u]=lw[u]= (++curtime);
	int chd=0;
	rep(i,0,v[u].size())
	{
		if(par==v[u][i])
		continue; 
		if(!vis[v[u][i]])
		{
			chd++; 
			par[v[u][i]]=u;
			dfs(v[u][i]);
			lw[u]=min(lw[u],lw[v[u][i]]);
			if(par[u]==-1 && chd>1)
			arp[u]=1;
			if(par[u]!=-1 && lw[v[u][i]]>=dis[u]) // Means No back edge
			arp[u]=1;
			if(lw[v[u][i]]>dis[u])
			brg[u].pb(v[u][i]);
		}
		else if(v[u][i]!=par[u])
		{
		lw[u]=min(lw[u],dis[v[u][i]]);
		}
	}
}
*/
/*
void Clps(string sb,int M , int* lps)
{
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<M)
	{
		if(sb[i]==sb[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len)
			len=lps[len-1];
			else
			lps[i]=0 , i++;
		}
	}
}
void KMP(string s,string sb)
{
	int M=sb.length();
	int N= s.length();
	int lps[M];
	Clps(sb,M,lps);
	int i=0,j=0;
	while(i<N)
	{
		if(sb[j]==s[i])
		{
			i++; j++;
		}
		if(j==M)
		{
			cout<<"At index :"<<(i-j);
			j=lps[j-1];
		}
		else if(i<N && sb[j]!=s[i])
		{
			if(j)
			j=lps[j-1];
			else
			i++;
		}
	}
}
*/
/*
int buildST(int a[], int ss, int se, int st[], int si)
{
	if(ss==se)
	{
		st[si]==a[ss];
		return st[si];
	}
	int mid=ss+(se-ss)/2;
	st[si]=buildST(a,ss,mid,st,2*si+1)+buildST(a,mid+1,se,st,2*si+2);
	return st[si];
}
void updateST(int st[],int ss,int se,int pos,int diff,int si)
{
	if(pos<ss || pos>se)
	return;
	st[si]+=diff;
	if(ss!=se)
	{
	int mid=ss+(se-ss)/2;
	updateST(st,ss,mid,pos,diff,2*si+1);
	updateST(st,mid+1,se,pos,diff,2*si+2);
	}
}
int getsumST(int st[],int ss,int se,int qs,int qe,int si)
{
	if(qs<=ss && qe>=se)
	return st[si];
	if(se<qs || ss>qe)
	return 0;
	int mid=ss+(se-ss)/2;
	return getsumST(st,ss,mid,qs,qe,2*si+1) + getsumST(st,mid+1,se,qs,qe,2*si+2);
}
*/
/*
int buildMST(int a[],int ss,int se,int st[],int si)
{
	if(ss==se)
	{
	st[si]=a[ss];	
	return st[si];
	}
	int mid=ss+(se-ss)/2;
	st[si]=min(buildMST(a,ss,mid,st,2*si+1),buildMST(a,mid+1,se,st,2*si+2));
	return st[si];
}
int RMQ(int st[],int ss,int se,int qs,int qe,int si)
{
	if(qs<=ss && qe>=se)
	return st[si];
	if(se<qs || ss>qe)
	return INT_MAX;
	int mid=ss+(se-ss)/2;
	return min(RMQ(st,ss,mid,qs,qe,2*si+1),RMQ(st,mid+1,se,qs,qe,2*si+2));
}
*/
/*
int getsumBIT(int BT[],int si)
{
int sum=0;
si+=1;
while(si>0)
{
	sum+=BT[si];
	si-= si&(-si);
}
return sum;
}
void updateBIT(int BT[],int n,int si,int val)
{
si+=1;
while(si<=n)
{
BT[si]+=val;
si+= si & (-si);
}
}
*/
/*
void merge(int *a,int st,int nd)
{
	int mid=(st+nd)/2;
	int i=st, j=mid+1,k=st;
	int temp[100];
	while(i<=mid && j<=nd)
	{
		if(a[i]<a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
		}
	}
	while(i<=mid)
	temp[k++]=a[i++];
	while(j<=nd)
	temp[k++]=a[j++];
	rep(l,st,nd+1)
	a[l]=temp[l];
}

void mergesort(int *a,int st,int nd) // 0 to n-1
{
	if(st>=nd)
	return;
	int mid=(st+nd)/2;
	mergesort(a,st,mid);
	mergesort(a,mid+1,nd);
	
	merge(a,st,nd);
}
*/
/*
class A{
	int var;
	public:
		void display();
		friend void fun();
};
void A:: display()
{
cout<<"Regular funciton \n";	
}
void fun()
{
	cout<<"Friend function \n";
}
*/
void solve()
{

int n; cin>>n;
vector<ll> a(n);
rep(i,0,n)
cin>>a[i];
vector<ll> pre(n);
pre[n-1]=0ll;
for(int i=n-2;i>=0;i--)
{
	pre[i]=pre[i+1]+a[i+1];
	pre[i]%=INF;
}
ll ans=0;
rep(i,0,n-1)
{
	//cout<<pre[i]<<' ';
	ans+= (a[i]*pre[i] )%INF ;
	ans%=INF;
}
//cout<<"\n";
cout<<ans;
return;
}
int main()
{
ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
//	cin>>t;
while(t--)
{
solve();
}
return 0;
}

//  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHBYYYWMMMM#BYYTTTYWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMB9O1==?????zzCC111>>;;;;;;;;;;;<?TMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM9Olll=l======??????????>>>>>>;;;;;;;;;:;?TMMMMMMMMMMMMMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMMMMMMMMMMMM9ttlllllllll=l=======?????????>>>>>>;;;;;;;;;;?TMMMMMMMMMMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMMMMMMMMMBOttOtttttltlllllllll=======??????????>>>>>>>;;;;;;?TMMMMMMMMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMMMMMMMBttwOtttttttttttttlllllllll========?????????>>>>>>;;;;;<TMMMMMMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMMMMMBrwZrttttttttttttttttttlllllllllll======???????????>>>>>>;;?HMMMMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMMMMSw0trtrrtrtrttrtttttttttttttlllOllllll========????<<zz??>>>>>>ZMMMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMMMX0ttrtrOOttrttrttOOttttttttttttltwllllllllll========??wy?????>>>vZMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMM0ttrI+wV1rtttttttwZtttttttltttOwylOXOllllllllllll=l====1dkz???????vZdMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMSrrwrtwZCjttttttttwSttOlllltllllwtXOlZkOlllllllllllllll==z+dk===?????X2JMMMMMMMMMMMMM
//  MMMMMMMMMMMMMBrtwwtrw0<jttttttttOXllOttltllttllOZwHOtXkyltlllllllllllllll<+XZ======?dk?JMMMMMMMMMMMM
//  MMMMMMMMMMMMStwdZtwXC<+ttttttOOOd6ltZlltllllttllStWWOOHWytttttltltOllltllz:zHllll===zX=?dMMMMMMMMMMM
//  MMMMMMMMMMBrwdKOtwW3;;zrttttwZwXRlldOllltltlltttwlXvktdXWytltttttttOttlttl<<dklllllllZ===dMMMMMMMMMM
//  MMMMMMMMM8tQM#ttwW3;;;1trttwSwfUOlORltllltlllllldtX>dktDOWOtlttltttOOttltO<;+WOllllllXlllzMMMMMMMMMM
//  MMMMMMMM9OdM#Ottd$;;;;;<?1z0OKjRltd0llltOllllllldZX>?WOw_WWOtttttttttOttI<;;<dkttttllllllldMMMMMMMMM
//  MMMMMMM9wMMMSttwS<;;;;>;;;J<j>(I<?U111zltllllllld0X>~dkwl(WkttlttlOOwWk<;;:;;zHttttttwOllllMMMMMMMMM
//  MMMMMMBdMMM8tttdI+zttttttdSXt~dlzXwlllzzOzzzzzlldkW<~?kOk~?sx++++jdHmH6+++<;;jdZtttttdkOtlldMMMMMMMM
//  MMMMM#dMMM#tttw0+tttttttdKdf((RsdfRllllldZllltlldWK~~_W0w_~OWOlOdgg9ZtOWOtttz+wktttttdpktttwMMMMMMMM
//  MMMMMWMMMMSlttdIttttttOdWHH>~(IzWDRll=llzRlllzlldk$>++dkd<~_XkdgH9tttttdktttt+OkrttrtdfpkttOMMMMMMMM
//  MMMMNWMMM#Zttlk=tttttOXWWd$_.(IdW1R=llll=SlllzOldK<_._(kd6+-(MM9lltttttrWktttztWZttrwXppWttrMMMMMMMM
//  MMMMNMMMM#lltwDzttllOXyW0X:..(OXk<Rl=ll=lwOlllOld3<``.(Rd>~?CdklllltttttXdXttzOWktrwwWpfpkrtMMMMMMMM
//  MMMMMMMMM@ltldIzlttOXyW$w$```(OyD(Rl==llldZ=llIlw;~```-Xd:~~~~UkylltttAyHdgSrzObRtOXwpfppWrrMMMMMMMM
//  MMMMMMMMM@llldtlllldVyW+d>```.wZ$ wl==lI=wRl=ll=w<```` dd_..~~(RZXOQdggHH9ZwrzwHWrdXXppfppkrMMMMMMMM
//  MMMMMMMMM#llldlltlwyyyD(S-...,Wk] zI=l=llzWzl=l=P~```` jZ``...~zQkH@MBUtrZtrtldHRdSdpfpffpkwMMMMMMMM
//  MMMMNMMMMNZllXtllldVyW3(Mf=<ONMHP~(k===l=zdk=lld3```...(C````..(M96lttttrrtrrtdHWHXpfpppfpRwMMMMMMMM
//  MMMMMMMMMMNzzWZllzyyyy(W@`  =~MWK6 jz=lzlzvRz=lZ`.I+JgkWm&-. `..(ZltlttttrtttrWWHppfppfpppSdMMMMMMMM
//  MMMMMMMMMMMkAWRllzVyyS_(b    .MNHU-(Uz=lI={XkzO>.dVT7<TMHMNHHx-.(kwZyltttrtrrdHHpfppfpffpp0dMMMMMMMM
//  MMMMMMMMMMMMKyWzOzyyyk.`<!  hdWMH]``(S==t=l(kX2 ?_`    WMMHH#HH+.XwkwOttttrwrZ~(HfpfpppfpWwXMMMMMMMM
//  MMMMMMMMMMMMMHWROOyyyW;` `. (WVM#b```(0=zzz wX!```  a.dM#NM@N(4WhXkXkWtttttwd3O_(HpffpfpfWwSMMMMMMMM
//  MMMMMMMMMMMMNZvWzXXyyXP```-_ ?o+?!````.4=Z=`(:````  HpbNNMHHH (C=XXyWZWttrdwf:(>.dfppffppSXSMMMMMMMM
//  MMMMMMMMMMMMMRzuHzXyZXH.``````````````` ?zz ``````` ZKvTHHbWt `` XZyyHZWOdSZ<::~`(fpfpfffXp0WMMMMMMM
//  MMMMMMMMMMMMMKzyyHvyZZW____.`````````````.I_```````` ?nJzX7^````.WXWyyHyWKZ<:::_`Jffpfpfpfp0WMMMMMMM
//  MMMMMMMMMMMMM@zZyZWwWyXo-_~(~ ```````````` `````````````` _`````.WXkyyVWmWc::<~ .HffppfffffkXMMMMMMM
//  MMMMMMMMMMMMMKzZZZZXkUXr~....```````....```````````` ...  ````..JXWWyyW83vXx~..WfffVfWVffffkdMMMMMMM
//  MMMMMMMMMMMMMRzZZZZZZZZb````````````<````````````./<~._<_.____`(WfdyW3<:~~(XWkVVVVVVVHVVVVV0dMMMMMMM
//  MMMMMMMMMMMMMSzZZZZZZZWX-```````````````````````````.......~~._j9jX=_~~_(XZyVHHkyyyyWHyyykykOMMMMMMM
//  MMMMMMMMMMMMMSzuuuuuZXWZW,```````````````````````````````.``..(3<! ...JWyyXWyyyWHkyyWHyyyHyklMMMMMMM
//  MMMMMMMMMMMMNXzuuuXXuXSuuXh,```````` .... ```````````````````_~ .JWyyyyZyy0HyyZyyZyZXWZZZWHZIdMMMMMM
//  MMMMMMMMMMMMNwtuuuXkuXXuuuuXh,``````(:::~<?71(,``````````````.(UMNUkZZZZZZZHZZ0ZZZZZWWZZZWNXIdMMMMMM
//  MMMMMMMMMMMMNKOzuzXkuXuuuuuXuXW, ```` _~~~:~~(}```````````.(YC;::<kCfZZZZXO#ZZVZZZZZMZZuuMMNXzMMMMMM
//  MMMMMMMMMMMMHKOzzuXkzdzzzzuXXzuuU&.``````````````````` .JY>::::;;J=:dZuZuZd#uuruuuud#uuuXMMMNXdMMMMM
//  MMMMMMMMMMMMMNOvzzXkvMRzzzzXKzuzzzXh, `````````````..JC<;:;;:;;+7<:~(HHuXIdNuuzuuuXMSuuuWMMMMROMMMMM
//  MMMMMMMMMMMMMNvvvrdkvM#vzzzzHzzzzzuzzUG. ``` ...JdY<:;:;:::;;+v<~~~:(HpHmzMNXZzuzzd#zzzdMMMMMMRdMMMM
//  MMMMMMMMMMMMMNwrrvdRrMNwvvvvdRvvvzwkzzzzXWWHY=~~O+::::::::<+<~~~~~~~dppppWMMkZzzzwM#zzdMMMMMMMMNMMMM
//  MMMMMMMMMMMMMM#rrrwRrMMbOrrOZNkrvvvXwvvvvvwX;.~._W_:::::(?!~~~~~~~~(HpppppppHWdvwM#XwdMMMMMMMMMMNMMM
//  MMMMMMMMMMMMMMNyrrrRrWMMmzOrzdNyrrrZNvrwQWWfb....(r~~_J>_.....~.~~-dpfpffpfpppWHHMNdMMMMMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMNrtrStdMMMNxzrzMNmrrrdNWfVfffP._-.(~_J!............JpfpffpfpfffpppWNppppHMMMMMMMMMMMM
//  MMMMMMMMMMMMMMMMNOtXtdMMMMMNxzZMMNmgHyVVVVVW%..?/(.,(x-..........(HfffpffpffpffWHHffpffppfVyyWMMMMMM