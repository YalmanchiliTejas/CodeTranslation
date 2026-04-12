#include<bits/stdc++.h>

template<typename First, typename Second, typename Third>
struct triple {
   First first;
   Second second;
   Third third;
};
using namespace std;
void solve(){
    int b;
    cin>>b;
     int c=0;
     int mx=0;
    for(int i=0;i<b;i++){
       int u;
cin>>u;
    if(u>=mx){
      mx=u;
     }
    else 
        c++;
}
cout<<b-c;
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
