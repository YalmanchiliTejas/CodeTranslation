#include<bits/stdc++.h>
#define ll long long
#define int long long int
#define MOD 1000000007
#define mkp make_pair
#define maxN 100005
#define pb push_back
#define ff first
#define ss second
#define debug1(a) cout<<a<<endl;
#define debug2(a,b) cout<<a<<' '<<b<<endl;
#define debug3(a,b,c) cout<<a<<' '<<b<<' '<<c<<endl;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,a,b) for(int i=a;i<b;i++)
#define pi pair<int,int>
#define pii pair<int,pi>
#define mp map<int,int>
#define ump unordered_map<int,int>
#define  vi vector<int>
#define st set<int>
#define mst multiset<int>
#define pq priority_queue
#define mpq priority_queue<int,vector<int>,greater<int> >
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define in cin>>
#define out cout<<
using namespace std;
const int infi=1e9+7;
void printVector(vector<int> v){
    for(int i=0;i<(int)v.size();i++)
        cout<<v[i]<<" ";
    out endl;
}

void printArray(int arr[],int n)
{
   for(int i=0;i<n;i++)cout<<arr[i]<<' ';
cout<<endl;
}
 set<pair<int,int>> primeset;
 vi prime_number;
void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
        for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
           primeset.insert(mkp(p,1));
}
ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}
int32_t main()
{
fastio;
int t=1;
//in t;
while(t--){
string s;in s;
int a=0,b=0;
rep(i,s.size()){
    if(s[i]=='A') a++;
    else b++;
}
if(a!=0 && b!=0) cout<<"Yes";
else cout<<"No";
}
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
