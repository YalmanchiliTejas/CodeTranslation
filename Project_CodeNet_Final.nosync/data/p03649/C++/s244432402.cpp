#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1e9+7;

ll expo(ll a, ll b){
   ll ans = 1;
   while(b){
       if(b&1){
          ans = (ans*a)%mod;
       }
       a = (a*a)%mod;
       b /= 2;
   }
   return ans;
}

int lev[223456], vis[213456];
vector <int> primes;

void bfs(vector <vector <int> > &vec, int n){
    queue <int> q;
    q.push(n);
    vis[n] = 1;
    lev[n] = 0;
    while(!q.empty()){
          int n1 = q.front();
          q.pop();
          for(int i= 0; i < vec[n1].size(); i++){
              if(!vis[vec[n1][i]]){
                 q.push(vec[n1][i]);
                 vis[vec[n1][i]] = 1;
                 lev[vec[n1][i]] = lev[n1]+1;
              }
          }
    }
}
int ok(vector <ll> &vec){
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] >= vec.size()) return 1;
    }
    return 0;
}

int id[123456], sz[123456];

void init(int n){
     for(int i = 1; i <= n; i++){
         id[i] = i;
         sz[i] = 1;
     }
}

int root(int i){
    while(i != id[i]){
          id[i] = id[id[i]];
          i = id[i];
    }
    return i;
}

void union_find(int p, int q, int &max1){
    int i = root(p);
    int j = root(q);
    max1 = 0;
    if(i == j) return;
    if(sz[i] > sz[j]){
       id[j] = i;
       sz[i] += sz[j];
       max1 = sz[i];
    }
    else{
       id[i] = j;
       sz[j] += sz[i];
       max1 = sz[j];
    }
}
ll arr[12345];

int set1[123];

int main()
{
    int n;
    cin >> n;
    vector <ll> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    ll k = 0;
    while(ok(vec)){
          sort(vec.begin(), vec.end());
          ll k1 = vec[n-1]/n;
          k += k1;
          vec[n-1] = vec[n-1]%n;
          for(int i = 0; i < n-1; i++) vec[i] += k1;
    }
    cout << k;
}
