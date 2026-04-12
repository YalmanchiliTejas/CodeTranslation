#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
typedef complex<D> P;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){ll i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}
template<typename T>vector<T> & cset(vector<T> &A,T e=T()){for(auto &I:A){I=e;} return A;}


ll cnt=0;

ll query(ll a,ll b){
    cnt++;
    cout<<"? "<<a<<" "<<b<<endl;
    ll ret;
    cin>>ret;
    return ret;
}

void answer(vector<ll> A){
    cout<<"!";
    for(int i=0;i<A.size();i++){
        cout<<" "<<A[i];
    }
    cout<<endl;
}


int main(){
    ll n,s,t;
    cin>>n>>s>>t;
    map<ll,ll> M;
    set<ll> used;
    M[0]=s;
    ll dist=query(s,t);
    M[dist]=t;
    used.insert(s);
    used.insert(t);
    for(int i=1;i<=n;i++){
        if(used.count(i)){continue;}
        ll ret=query(s,i);
        if(ret>=dist || M.count(ret)){continue;}
        auto I=M.lower_bound(ret);
        auto T=I; T--;
        ll f=query(T->S,i),s=query(i,I->S);
        if(f+s==(I->F)-(T->F)){
            used.insert(i);
            M[T->F+f]=i;
        }
    }
    vector<ll> ans;
    for(auto &I:M){ans.push_back(I.S);}
    answer(ans);
    assert(cnt<=5*n);
    
    
    
    return 0;
}

