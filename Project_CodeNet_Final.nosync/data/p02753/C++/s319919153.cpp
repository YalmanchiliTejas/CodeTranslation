/*input
BBB

*/
#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 

using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(ll i=0;i<n;i++)
#define Fo(i,k,n) for(ll i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define ms(a,x) memset(a, x, sizeof(a));
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    //cout<<s<<endl;
    int ans[2] = {0};
    for(auto i:s){
    	if(i=='B')
    	ans[1]++;
    	else
    	ans[0]++;
    }
    //cout<<ans[0]<<ans[1]<<endl;
    if(ans[0]!=0 && ans[1]!=0){
    	cout<<"Yes"<<endl;
    }
    else{
    	cout<<"No"<<endl;
    }
    return 0;
}