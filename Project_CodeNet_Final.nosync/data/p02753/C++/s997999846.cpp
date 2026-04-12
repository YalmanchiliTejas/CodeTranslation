//#pragma GCC optimize "trapv"
//-D_GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define pm(m) for(auto itr=(m).begin();itr!=(m).end();itr++){itr->first<<" "<<itr->second<<"\n";}
#define int long long int
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define ii pair<int,int>
#define Max 100000+5
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f first
#define s second
#define pb push_back
#define bug(x) cout<<(x)<<" ";exit(0);
int mod = 1000000007;
int mod1 = 998244353;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<int> g[Max];
bool vis[Max];
int d, x, y;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
void ex(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        ex(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}


void dfs(int u){

	vis[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]!=1)
			dfs(v);
	}
}



int power(int a,int b){
    if(b==1)return a;
    if(a>mod)a%=mod;
    int r=1;
    while(b){
        if(b&1)r=r%mod*a%mod;
        a=a%mod*a%mod;
        b/=2;
    }
    return r;
}
class uf{
    vector<int> v;
    vector<int> sz;
    
    
    public :
    uf(int n){
        v.resize(n+1);
        iota(v.begin()+1,v.end(),1);
        sz.resize(n+1,1);
        //1 to sz
    }
    int root(int b){
        while(v[b]!=b){
            b = v[b];
        }   
        return b;
    }
    void join(int a, int b){
        //combine a and b
        
        int ra=root(a);
        int rb=root(b);
        if(ra==rb)return ;
        if(sz[ra]<sz[rb])swap(ra,rb);
        v[rb]=ra;
        sz[ra]+=sz[rb];
        
    }
    bool same(int a,int b){
        //same set
        return (root(a)==root(b));
    }
    int size(int a){
        return sz[root(a)];
    }
   
    
};
vector<int> matmul(vector<int> a,vector<int> b){
    vector<int> c(4,0);
    c[0] = (a[0]%mod*b[0]%mod + a[1]%mod*b[2]%mod)%mod;
    c[1] = (a[0]%mod*b[1]%mod + a[1]%mod*b[3]%mod)%mod;
    c[2] = (a[2]%mod*b[0]%mod + a[3]%mod*b[2]%mod)%mod;
    c[3] = (a[2]%mod*b[1]%mod + a[3]%mod*b[3]%mod)%mod;
    return c;
}
vector<int> id={1,0,0,1};

int32_t main(){
	IO
	//freopen("input.txt","r",stdin);
    	//freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    int l=0,r=0;
    for(int i=0;i<3;i++)if(s[i]=='A')l++;else r++;
    if(l!=0 and r!=0){
        cout<<"Yes";
    }
    else cout<<"No";
}