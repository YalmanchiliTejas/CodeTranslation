#pragma GCC optimize("-O3")

#include<bits/stdc++.h>
using namespace std;

using l = long int;
using ll =long long int;
using u64 = uint64_t;
// using u128 = __uint128_t;
#define imax INT_MAX
#define lmax LLONG_MAX
#define pb push_back
#define ld long double
#define pii pair<l,l> 
#define pll pair<ll,ll>
#define v vector
#define vl vector<l>
#define vll vector<ll>
#define vvl vector<vector<l>>
#define vvll vector<vector<ll>>
#define vv(a) vector<vector<a>> 
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x)rend()
#define f first
#define s second
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define rep(i, begin, end) \
        for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define tc l t=0;cin>>t;while(t--)

// ONLINE JUDGE START
#ifndef ONLINE_JUDGE
    // FILE

    #define file ofstream cout; ifstream cin; cout.open("output.txt"); cin.open("input.txt");  
    // DEBUG

    #define debug(x) cout<<"LINE NUMBER:     "<<__LINE__<<"\t :--> \t"<<#x<<"   =   "<<x<<endl;

#else 

    #define debug(x) 

#endif


// SYSTEM
#define DeBuG(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime=NULL;(blockTime==NULL?(blockTime=clock())!=NULL:false); \
            DeBuG("%s:%.4f s\n",d,(double)(clock()-blockTime)/CLOCKS_PER_SEC))

// OVERLOADING
istream& operator >> (istream& cin,vll &a){
    for(auto &i:a)cin>>i;
    return cin;
}
ostream& operator << (ostream& cout,pll &a){
    cout<<a.f<<" "<<a.s<<"\t";
    return cout;
}
ostream& operator << (ostream& cout,vl &a){
    for(auto &i:a)cout<<i<<" ";
    return cout;
}
ostream& operator << (ostream& cout,vll &a){
    for(auto &i:a)cout<<i<<" ";
    return cout;
}
ostream& operator << (ostream& cout,v<pll> &a){
    for(auto &i:a)cout<<i<<"\t";
    return cout;
}
ostream& operator << (ostream& cout,vvl &a){
    for(auto &i:a){cout<<i<<endl;}
    return cout;
}
ostream& operator << (ostream& cout,vvll &a){
    for(auto &i:a){cout<<i<<endl;}
    return cout;
}
ostream& operator << (ostream& cout,map<l,l> &a){
    for(auto &i:a){
        cout<<i.f<<" ";
    }
    return cout;
}


// GLOBAL VARIABLE AND FUNTIONS
const ll inf = 1e9+7;

int main()
{
#ifndef ONLINE_JUDGE
    // file;
#endif 
	fast;

     ll n,m;cin>>n>>m;
     string st;
     st= (n==m ? "Yes" : "No");
     cout<<st;

#ifndef ONLINE_JUDGE
    // cerr << "Time elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
#endif
    return 0;
}
