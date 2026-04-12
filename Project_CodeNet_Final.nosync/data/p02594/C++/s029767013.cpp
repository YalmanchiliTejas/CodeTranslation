#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef list<int> li;

#define all(x) x.begin(),x.end()
#define YES out("YES")
#define NO out("NO")
#define out(x){cout << x << "\n"; return;}
#define FAST     ios_base::sync_with_stdio(false); cin.tie(NULL)


const int INF=INT_MAX;
const ld PI=acos(-1);//3.1415926535897932384626433
const ld E=2.71828183;
const int MOD=1e9+7;

struct segment_tree{

    vector<ull>tree;
    int size;
    ll DEF;
    void init(int n){
        size=1;
        DEF=INF;
        while(size<n)size*=2;
        tree=vector<ull>(2*size,0);
    }

    ull merge(ull a,ull b){return a|b;}
    bool search(ull x,int l,int r){
        int m=(l+r)/2;
        if(size<=l || size<=r || l>r) return false;
        if(tree[m]==x)
            return true;
        else if(tree[m]>x)
            return search(x,l,m);
        else
            return search(x,m,r);
    }
    bool search(ull x){
        return search(x,0,size);
    }
    void set(int i,int x,ull v,int lx, int rx){
        if(rx-lx==1){
            tree[x]=v;
            return;
        }
        int m=(rx+lx)/2;
        if(i<m){
            set(i,2*x+1,v,lx,m);
        }
        else{
            set(i,2*x+2,v,m,rx);
        }
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);
    }
    void set(int i,ull v){
        set(i,0,v,0,size);
    }
    ull sum(int l,int r,int x,int lx,int rx){
        if(r<=lx || rx<=l) return 0;//change
        else if(l<=lx && rx<=r)return tree[x];
        int m=(lx+rx)/2;
        return merge(sum(l,r,2*x+1,lx,m),sum(l,r,2*x+2,m,rx));
    }
    ull sum(int l,int r){
        return sum(l,r,0,0,size);
    }
    void print(){
        for(int i=0; i<tree.size(); i++)
            cout << to_string(tree[i]) << " ";
        cout << "\n";
    }
};


ll gcd(ll a,ll b){ return (a%b==0? b: gcd(b,a%b)) ;}
ld log (ld a,ld b){return log(b)/log(a);}
ll lcm(ll a,ll b){return (a/gcd(a,b)*b);}

ll power(ll base, ll exp,ll M=LLONG_MAX){//(base^exp)%M
    ll res=1;
    while(exp){
        if(exp%2==1)res=((res%M)*(base%M))%M;
        base=((base%M)*(base%M))%M;
        exp/=2;
    }
    return res;
}

void solve();
int main(){
    FAST;
    int t=1;
    //  cin >> t;

    while(t--)
        solve();
    return 0;
}

void solve(){
    int n;
    cin >> n;
    if(30<=n)out("Yes")
    else out("No")
}