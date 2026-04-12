#include<bits/stdc++.h>
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scl1(a) scanf("%lld",&a)
#define scl2(a,b) scanf("%lld%lld",&a,&b)
#define scl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define pf1(a) printf("%d ",a)
#define pfl1(a) printf("%lld ",a)
#define pfn printf("\n")
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vl vector<long long>
#define si set<int>
#define sl set<long long>
#define msi multi_set<int>
#define msl multi_set<long long>
#define usi unordered_set<int>
#define usl unordered_set<long long>
#define mii map<int,int>
#define mli map<long long,int>
#define mll map<long long,long long>
#define umii unordered_map<int,int>
#define umli unordered_map<long long,int>
#define umll unordered_map<long long,long long>
#define lp(i,a,b) for(int i=a;i<b;i++)
#define rlp(i,a,b) for(int i=a;i>b;i--)
#define dslp(it,c) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define pb push_back
#define pf push_front
#define ft first
#define sd second
#define N 100001
#define mod 1000000007
#define mod1 100000000
using namespace std;
typedef vector<vector<ll> > matrix;

int main(){
    int n;
    sc1(n);
    ll int a,x=0,y=0;
    lp(i,0,n){
        scl1(a);
        y= ( (y%mod)+(( (x%mod)*(a%mod) )%mod) )%mod;
        x=(x%mod+a%mod)%mod;
    }
    cout<<y<<endl;
}