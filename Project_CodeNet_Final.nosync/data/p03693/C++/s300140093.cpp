#include<bits/stdc++.h>

template<typename First, typename Second, typename Third>
struct triple {
   First first;
   Second second;
   Third third;
};
#define  ll long long 
using namespace std;

void solve(){
   int x,y,z;
    cin>>x>>y>>z;
    string s=to_string(x);
    s+=to_string(y);
    s+=to_string(z);
    if(stoi(s)%4==0)
         cout<<"YES";
    else 
         cout<<"NO";
}
int main(){

  std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  solve();
  return 0;
}
