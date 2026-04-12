#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int ll;
#define f(i, n) for(int i = 0; i < n; ++i)
#define pb push_back

void input(){
    ll n; cin >> n;
    vector<ll>a(n);
    f(i, n) cin >> a[i];
    multiset<int>s;
    int ans = 0;
    for(int i = 0; i < n; ++i){
       int x = a[i];
       auto it = s.find(x);
       if(it != s.end()){
        if(it != s.begin()){
           --it;
           s.erase(it);
           s.insert(x);
        }else{
            ++ans;s.insert(x);
        }
       }else{
            auto it = s.upper_bound(x);
            if(it == s.begin()){
                ++ans;s.insert(x);
            }else{
              --it;
              s.erase(it);
              s.insert(x);
            }
       }
    }
    cout << ans <<"\n";
}
int main()
{
 input();
 return 0;
}
