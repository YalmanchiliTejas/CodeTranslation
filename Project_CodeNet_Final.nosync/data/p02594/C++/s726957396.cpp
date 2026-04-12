#include <bits/stdc++.h>
#include<numeric>
#include<cstdlib>
#define ll long long int
#define all(x) x.begin(),x.end()
 
 #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define v vector<long long int> 
#define vv vector< int> 
#define gcd(m,n) __gcd(m,n)
#define vp vector<pair<long long int ,long long int>>
#define pb push_back
#define mp make_pair
#define pp pop_back
#define iter vector<int>::iterator
#define pa pair<long long int ,long long int> 
#define f(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,n) for (ll i=a ; i<n ;i+=1)
#define fe(d,e) for(auto d:e)
#define mod 1000000007
#define F first
#define S second
#define sett set<long long int>
#define um unordered_map<ll,ll>
# define N 100005LL
using namespace std;

vector<vector<ll>> graph(200005);
ll visited[200005]; 

void dfs(ll node){
    visited[node]=1;
    cout<<node<<" ";
    for (ll u:graph[node]){
        if(!visited[u])dfs(u);
    }
}



int main(){
    ll n;
    cin>>n;
    if (n>=30)cout<<"Yes\n";
    else cout<<"No\n";


    

}
    
