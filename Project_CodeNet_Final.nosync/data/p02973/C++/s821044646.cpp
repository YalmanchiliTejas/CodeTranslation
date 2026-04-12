#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define drep(i,a,b) for(int i=(a); i>=(b);i--) 

const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;

multiset<int>q;
int a[maxn];

int main()
{
   ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
   int n; cin >> n;
   rep(i,1,n) cin >> a[i];
   rep(i,1,n){
      auto it = q.lower_bound(a[i]);
      if(it == q.begin())q.insert(a[i]);
      else{
          --it;
          q.erase(it);
          q.insert(a[i]);
      }
   }
   cout << q.size() << endl;
   return 0;
}