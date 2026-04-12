#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
typedef long long ll;

vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];
int main() {
     int n;
       cin >> n;
       vector<map<char,int>> d(n);
       rep(i,0,n){
           string s;
           cin >> s;
           rep(j,0,s.size()){
               d[i][s[j]]++;
           }
       }
       map<char,int> m = d[0];
       for(auto x:m){
           char k = x.first;
           rep(i,0,n) m[k] = min(m[k],d[i][k]);
       }
       for(auto x:m){
           rep(i,0,x.second) cout << x.first;
       }
       cout << endl;
}

