#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<ctime>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<bitset>
#include<cassert>
#define ll long long 
#define ull unsigned long long 
#define mem(a) memset(a,0,sizeof(a)) 
#define fio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define EXIT exit(0)
#define all(a) (a).begin(),(a).end()
//loop 
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define cFor(i,a,b) for(int i=(a);i>(b);i--)
#define cFOR(i,a,b) for(int i=(a);i>=(b);i--)
#define lFor(i,a,b) for(ll i=(a);i<(b);i++)
#define lFOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define lcFor(i,a,b) for(ll i=(a);i>(b);i--)
#define lcFOR(i,a,b) for(ll i=(a);i>=(b);i--)
//debug
#define dbg(a) cout<<#a<<"="<<a<<endl
#define inthis cout<<"--------this\n"
//operator
#define pb push_back
#define ins insert
#define era erase
#define fin find 
//pair
#define pr pair
#define mkp(a,b) make_pair(a,b)
#define fi first
#define se second
////pair int
#define prii pair<int,int>
#define prib pair<int,bool>
#define pril pair<int,long long>
#define pric pair<int,char>
#define pris pair<int,string>
////pair long long
#define prll pair<long long,long long>
#define prlb pair<long long,bool>
#define prli pair<long long,int>
#define prlc pair<long long,char>
#define prls pair<long long,string>
////pair char
#define prcc pair<char,char>
#define prcb pair<char,bool>
#define prci pair<char,int>
#define prcl pair<char,long long>
#define prcs pair<char,string>
////pair string
#define prss pair<string,string>
#define prsb pair<string,bool>
#define prsi pair<string,int>
#define prsl pair<string,long long>
#define prsc pair<string,char>
//vector
#define vec vector
#define vi vector<int>
#define vii vector<vector<int>>
//map
#define mp map
////map int
#define mpii map<int,int>
#define mpib map<int,bool>
#define mpic map<int,char>
#define mpis map<int,string>
#define mpil map<int,long long>
////map long long 
#define mpll map<long long,long long>
#define mplb map<long long,bool>
#define mplc map<long long,bool>
#define mpls map<long long,string>
#define mpli map<long long,int>
////map char
#define mpcc map<char,char>
#define mpci map<char,int>
#define mpcb map<char,bool>
#define mpcl map<char,long long>
#define mpcs map<char,string>
////map string
#define mpss map<string,string>
#define mpsi map<string,int>
#define mpsb map<string,bool>
#define mpsl map<string,long long>
#define mpsc map<string,char>
//queue
#define que queue
#define quei queue<int>
#define quel queue<long long>
#define quec queue<char>
#define ques queue<string>
//iterator
#define iter iterator
#define ivec(a) vector<a>::iterator
#define iset(a) set<a>::iterator 
#define imp2(a,b) map<a,b>::iterator
#define imp3(a,b,c) map<a,b,c>::iterator
#define imp4(a,b,c,d) map<a,b,c,d>::iterator

using namespace std;

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll qpow(ll a,ll p,ll mod){ll res=1;a%=mod;assert(p>=0);for(;p;p>>=1){if(p&1) res=res*a%mod;a=a*a%mod;}return res;}
ll lcm(ll x,ll y){return x*y/gcd(x,y);}
/*
const int maxsize=
struct edge{
	int nod,nxt;
			
}e[maxsize<<1];
int nume=0,pa[maxsize],head[maxsize];
void add(int u,int v){
	e[++nume].nod=v;
	e[nume].nxt=head[u];
	head[u]=nume;
}
void init(){
	
}
bool vis[maxsize];
void bfs(){
	
}
void dfs(){

}
*/

int main(){
	//fio;
    string s;
    cin>>s;
    bool alla=1,allb=1;
    For(i,0,s.size()){
        if(s[i]=='A')
            allb=0;
        else
            alla=0;
    }
    if(alla||allb)
        cout<<"No\n";
    else
    {
            cout<<"Yes\n";
    }
    
}