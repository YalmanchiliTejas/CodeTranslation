#include<bits/stdc++.h>
#define all(v) v.begin(), v.end() 
using namespace std;
typedef long long ll;

int n, m;
vector<int> id;

map<pair<int, int>, int> mp;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   for(int i=0; i<m; ++i) {
       int a, b;
       cin >> a >> b;
       --a, --b;
       mp[{a, b}] = 1;
       mp[{b, a}] = 1;
   }
   id.resize(n);
   iota(all(id), 0);
   int res = 0;
   do {
        if(id[0]) continue;
        int flag = 0;
        for(int i=0; i<n-1; ++i) {
            if(!mp[{id[i], id[i+1]}]) {
                flag = 1;
                break;
            }
        }
        if(!flag) ++res;
   }while(next_permutation(all(id)));
   cout << res << "\n";
   return 0;
} 
