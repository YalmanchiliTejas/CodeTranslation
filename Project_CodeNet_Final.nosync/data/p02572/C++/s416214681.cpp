#include<bits/stdc++.h>
#include<stdio.h>
    
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define _USE_MATH_DEFINES
#define f first
//#define s second
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000000000000
#define MAXN (int)(1e7)+1
#define MOD 1000000007
    
using namespace std;
    
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pwi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< vector<pair<ll,ll > > > wGraph;
typedef vector<vector<ll> > graph;
//typedef vector<vector<ll> > matrix;
    

ll mult(ll a, ll b){
    ll mod_a = a%MOD;
    ll mod_b = b%MOD;

    return (mod_a * mod_b)%MOD;
}


ll som(ll a, ll b){
    ll mod_a = a%MOD;
    ll mod_b = b%MOD;
    
    return (mod_a + mod_b)%MOD;
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<std::fixed;
    cout<<std::setprecision(2);
    
    ll N;
    ll soma_total = 0;
       
    cin>>N;

    vector<ll> A(N);
    for(int i = 0; i<N; ++i){
        cin>>A[i];
        soma_total+=A[i];
    }

    ll somatorio_produtos = 0;
    for(int i = 0; i<N; ++i){
        soma_total-=A[i];
        somatorio_produtos = som(somatorio_produtos, mult(A[i], soma_total));
    }

    cout<<somatorio_produtos<<endl;

    return 0;   
}