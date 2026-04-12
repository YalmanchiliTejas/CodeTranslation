#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef complex<double> point;
ll mod = 1e9 + 7;
#define EPS 1e-1
#define PI 3.141592653589
#define point complex<ld>
#define dot(a, b) (conj(a) * b).real()
#define cross(a, b) (conj(a) * b).imag()
#define line tuple<ll, ll, ll>
#define X real()
#define Y imag()
#define MAXN 100001
int spf[MAXN];

// int dx[] = { 0, 0, 1, -1 };
// int dy[] = { 1, -1, 0, 0 };

#define iofile                                                                 \
  freopen("input.txt", "r", stdin);                                            \
  freopen("output.txt", "w", stdout);
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

void primeFactors(ll n, vector<ll> &vec)
{

    while (n % 2 == 0)
    {
        vec.push_back(2);
        n = n / 2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            vec.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
    {
        vec.push_back(n);
    }
}

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

ll Lcm(ll a, ll b)
{
    return ((a * b) / gcd(a, b));
}

line getL(point p1, point p2)
{
    ll a, b, c;
    a = p2.Y - p1.Y;
    b = p1.X - p2.X;
    c = -a * p1.X - b * p1.Y;
    ll gcdres = abs(gcd(a, gcd(b, c)));
    if (a < 0 || a == 0 && b < 0)
    {
        gcdres *= -1;
    }
    a /= gcdres;
    b /= gcdres;
    c /= gcdres;
    return line(a, b, c);
}

ll fastpow(ll base, ll pow)
{
    if (!base)
        return 0;
    if (!pow)
        return 1;
    if (pow == 1)
        return base;
    ll x = fastpow(base, pow / 2) % mod;
    x *= x;
    x %= mod;
    if (pow % 2)
        x *= base;
    return x % mod;
}

ll inverse(ll x)
{
    return fastpow(x, mod - 2) % mod;
}

ld disty(pair<double, double> a, pair<double, double> b)
{
    return sqrt(pow(b.second - a.second, 2.0) + pow(b.first - a.first, 2.0));
}

/*ll fact[(int)1e6 + 5], inv[(int)1e6 + 5];
void init()
{
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = inverse(fact[i]);
    }
}*/

void factorize(ll x, set<ll> &ss)
{
    while (x % 2 == 0)
        ss.insert(2), x /= 2;
    for (int i = 3; i <= sqrt(x); i += 2)
        while (x % i == 0)
            ss.insert(i), x /= i;
    if (x > 2)
        ss.insert(x);
}

/*ll ncr(ll n, ll r)
{
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}*/

void SieveOfEratosthenes(ll n, bool prime[])
{

    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
void divisors(ll n, vector<ll> &vec)
{
    // vec.push_back(1);
    for (ll i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0 && i != sqrt(n))
        {
            vec.push_back(i);
            vec.push_back(n / i);
        }
        else if (n % i == 0)
        {
            vec.push_back(i);
        }
    }
    //if(n!=1){vec.push_back(n);}
}

bool isprime(ll n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

point rot(point p, ld angle)
{
    return (p * polar((ld)1.0, angle));
}

point rotA(point p, point A, ld angle)
{
    return (((p - A) * polar((ld)1, angle)) + A);
}

ld distance(point a, point b)
{
    ld x1 = a.X, y1 = a.Y, x2 = b.X, y2 = b.Y;
    return pow(y2 - y1, 2) + pow(x2 - x1, 2);
}

int distSq(pair<ll, ll> p, pair<ll, ll> q)
{
    return (p.first - q.first) * (p.first - q.first) +
           (p.second - q.second) * (p.second - q.second);
}

bool isSquare(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3,
              pair<ll, ll> p4)
{
    ll d2 = distSq(p1, p2);
    ll d3 = distSq(p1, p3);
    ll d4 = distSq(p1, p4);
    if (d2 == d3 && 2 * d2 == d4 && 2 * d2 == distSq(p2, p3))
    {
        int d = distSq(p2, p4);
        return (d == distSq(p3, p4) && d == d2);
    }

    // The below two cases are similar to above case
    if (d3 == d4 && 2 * d3 == d2 && 2 * d3 == distSq(p3, p4))
    {
        int d = distSq(p2, p3);
        return (d == distSq(p2, p4) && d == d3);
    }
    if (d2 == d4 && 2 * d2 == d3 && 2 * d2 == distSq(p2, p4))
    {
        int d = distSq(p2, p3);
        return (d == distSq(p3, p4) && d == d2);
    }

    return false;
}

ll FP(ll base, ll power, ll m)
{

    if (power == 0)
    {
        return 1;
    }
    else if (power % 2 == 0)
    {
        ll res = FP(base, power / 2, m);
        return (res % m * res % m) % m;
    }
    else
    {
        ll res = FP(base, power / 2, m);
        return ((((base % m * (res % m)) % m) * (res % m) % m) % m);
    }
}
ll EGCD(ll a, ll b, ll &x, ll &y)
{

    if (b == 0)
    {
        x = 0;
        y = 1;
        return a;
    }
    else
    {
        ll ans = EGCD(b, a % b, x, y);
        ll tmp = x;
        x = y - (a / b) * x;
        y = tmp;
        return ans;
    }
}
// ll f[(int)1e7+7],in[(int)1e7+7];
/*void prec(ull n){
f[0]=1;
in[0]=1;
for(int i=1;i<=n;++i){
    f[i]=(f[i-1]*i)%mod;
    in[i]=FP(f[i],mod-2,mod);
}
}
ll npr(ll n,ll r){
    return (f[n]*in[n-r])%mod;
}
ll NCR(ll n,ll r){
return (((f[n]*in[n-r])%mod)*in[r])%mod;
}*/
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)


        spf[i] = i;

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {

        if (spf[i] == i)
        {

            for (int j=i*i; j<MAXN; j+=i)

                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

set<int> getFactorization(int x)
{
    set<int> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}



void helper(int* a,int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[10];
    while(i<=mid && j<=e)
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
    {
        temp[k++]=a[i++];
    }
    while(j<=e)
    {
        temp[k++]=a[j++];
    }
    for(int h=s; h<=e; ++h)
    {
        a[h]=temp[h];
    }
}

void mergesort(int* arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    helper(arr,s,e);

}
ll newfastpow(ll base,ll pow){
if(pow==0){return 1;}
else if(pow%2==0){
    ll x=newfastpow(base,pow/2);
    return x*x;
}
else{
    ll x=newfastpow(base,pow/2);
    return x*x*base;
}
}


/*ll saved[500][500];
vector<ll>arr;
ll coins(ll wanted,ll idx){
   if(wanted==0){return saved[wanted][idx]=1;}
   if(idx==arr.size()){return saved[wanted][idx]=0;}
   if(saved[wanted][idx]!=0){return saved[wanted][idx];}
   else if(arr[idx]<=wanted){
     return saved[wanted][idx]=coins(wanted-arr[idx],idx)+coins(wanted,idx+1);
   }
   else{
    return saved[wanted][idx]=coins(wanted,idx+1);
   }

}*/
ll fact(ll n){
if(n==0){return 1;}
else{return n*fact(n-1);}
}

int pivot(int start,int ending,int arr[],int N)
{
            int mid;
            double before, after;
            while (start <= ending)
            {
                mid = (start + ending) / 2;
                if (mid == 0) { before = arr[N - 1]; }
                else { before = arr[mid - 1]; }
                if (mid == N - 1) { after = arr[0]; }
                else { after = arr[mid + 1]; }
                if(arr[mid]>after && arr[mid] > before) { break; }
                else if (after > before) { return pivot(mid + 1, ending, arr, N); }
                else { return pivot(start, mid - 1, arr, N); }
            }
            return arr[mid];
}
int fib(int n,int arr[]){
if(n<=1){return arr[n]=1;}
if(arr[n-1]==-1){arr[n-1]=fib(n-1,arr);}
if(arr[n-2]==-1){arr[n-2]=fib(n-2,arr);}
return arr[n-1]+arr[n-2];
}
ll calcdec(string s){
    ll power=s.size()-1;
    ll num=0;
for(int i=0;i<s.size();++i){
    ll val=s[i]-'0';
    if(val==1){num+=(newfastpow(2,power)*val);}
    power--;
}
return num;
}


/*ll dijekstra()
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >pq;
    for(int i=2; i<=n; ++i)
    {
        costs[i]=1e15;
        parent[i]=-1;
    }
    costs[1]=0;
    pq.push({costs[1],1});
    while(!pq.empty())
    {
        ll currnode=pq.top().second;
        ll currcst=pq.top().first;
        pq.pop();
        if(currnode==n)
        {
            break;
        }
        if(costs[currnode]<currcst)
        {
            continue;
        }
        for(int i=0; i<graph[currnode].size(); ++i)
        {
             ll nextnode=graph[currnode][i].first;
             ll nextnodeweight=graph[currnode][i].second;

            if(costs[nextnode]>currcst+nextnodeweight)
            {
                costs[nextnode]=currcst+nextnodeweight;
                parent[nextnode]=currnode;
                pq.push({costs[nextnode],nextnode});
            }
        }
    }
    return costs[n];
}*/
//vector<vector<ll> >graph;
//bool visited[1000005];

/*void TS(int node){
if(visited[node]){return;}
visited[node]=true;
for(int i=0;i<graph[node].size();++i){
    int child=graph[node][i];
    if(!visited[child]){TS(child);}
}
cout<<node<<"\n";
}*/
string toString(ll num){
   string s="";
   if(num==0){return "0";}
   while(num>0){
     char x=(num%10)+'0';
     s=x+s;
     num/=10;
   }
   return s;
}

ll nc;
ll rep[100005];
ll sz[100005];
ll maxx=1;
void StartDSU(ll n){
for(int i=0;i<=n;++i){
    rep[i]=i;
    sz[i]=1;
}
nc=n;
}
ll findu(ll u){
  if(rep[u]==u){return u;}
  else{return rep[u]=findu(rep[u]);}
}
void Join(ll a,ll b){
  a=findu(rep[a]);
  b=findu(rep[b]);
  if(a==b){return;}
  if(sz[a]<sz[b]){swap(a,b);}
  rep[b]=a;
  sz[a]+=sz[b];
  nc-=1;
  maxx=max(maxx,sz[a]);
}
vector<pair<ll,pair<ll,ll> > >edges;

ll kruskal(ll n){
 ll cost=0;
 StartDSU(n);

 for(int i=0;i<edges.size();++i){
    ll from=edges[i].second.first;
    ll to=edges[i].second.second;
    ll w=edges[i].first;
    if(findu(from)==findu(to)){continue;}
    else{
        Join(from,to);
        cost+=w;

    }
 }
 return cost;
}
struct wasla{
ll fromx,fromy,tox,toy;
};
int main()
{

    //fastio
    //freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    ll n;
    cin>>n;
    ll num=0;
    vector<pair<ll,ll> >xx,yy;
    map<pair<ll,ll>,ll>id;
    for(ll i=0;i<n;++i){
        ll a,b;
        cin>>a>>b;
        pair<ll,ll>p(a,b),pp(b,a);
        xx.push_back(p);
        yy.push_back(pp);
        id[{a,b}]=num;
        num++;
    }
    sort(xx.begin(),xx.end());
    sort(yy.begin(),yy.end());
    map<ll,vector<wasla> >mp;
    map<ll,vector<wasla> >::iterator it;
    for(ll i=0;i<xx.size()-1;++i){
        ll val1=abs(xx[i].first-xx[i+1].first);
        ll val2=abs(yy[i].first-yy[i+1].first);
        wasla w1,w2;
        w1.fromx=xx[i].first;
        w1.fromy=xx[i].second;
        w1.tox=xx[i+1].first;
        w1.toy=xx[i+1].second;
        w2.fromx=yy[i].second;
        w2.fromy=yy[i].first;
        w2.tox=yy[i+1].second;
        w2.toy=yy[i+1].first;
        mp[val1].push_back(w1);
        mp[val2].push_back(w2);
    }
    StartDSU(n);
    ll finalcost=0;
    for(it=mp.begin();it!=mp.end();++it){
        ll pay=it->first;
        for(ll i=0;i<mp[pay].size();++i){
            pair<ll,ll>from(mp[pay][i].fromx,mp[pay][i].fromy),to(mp[pay][i].tox,mp[pay][i].toy);
            if(findu(id[from])==findu(id[to])){continue;}
            else{
                Join(id[from],id[to]);
                finalcost+=pay;
            }
        }
    }
    cout<<finalcost<<"\n";
	return 0;

}

