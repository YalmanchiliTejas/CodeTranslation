#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 1000000000
#define mod 1000000007
#define vi vector <int>
#define vll vector<long long>
#define ii pair<int,int>
#define vii vector<pair<int,int>>
#define ll long long 
#define ld long double
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define sz(a) (int)a.size()

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
/*struct item{
    int m,c;
};					// change item according to the question;
struct segtree{
	int size;
	vector<item>values;
	void intit(int n){
		size=1;
		while(size<n)size*=2;
		values.resize(2*size);
	}
    item merge(item a,item b){
        if(a.m<b.m)return a;
        if(b.m<a.m)return b;
        if(a.m==b.m)return {a.m,a.c+b.c}; 
    }
    item single(int v){
        return {v,1};
    }
    item NEUTRAL_ELEMENT={INF,1};
    void build(vi &a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<sz(a)){
                values[x]=single(a[lx]);
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }
    void build(vi &a){
        build(a,0,0,size);
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            values[x]=single(v);
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    item calc(int l,int r,int x,int lx,int rx){
        if(lx>=r||rx<=l)return NEUTRAL_ELEMENT;
        if(l<=lx && rx<=r)return values[x];
        int m=(lx+rx)/2;
        item s1=calc(l,r,2*x+1,lx,m);
        item s2=calc(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }
    item calc(int l,int r){
        return calc(l,r,0,0,size);
    }
};*/
int main(){
	int x;
    cin>>x;
    if(x>=30)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
