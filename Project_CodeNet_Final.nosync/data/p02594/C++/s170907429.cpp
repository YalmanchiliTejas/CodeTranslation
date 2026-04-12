#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp  make_pair
#define pb  push_back
void c_p_c(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void solve(){
    int x;
    cin>>x;
    if(x>=30){
        cout<<"Yes"<<endl;
        return;
    }
    else{
        cout<<"No"<<endl;
        return;
    }
}
int32_t main(){
    c_p_c();
    int t;
    t=1;
    //cin>>t;
    while(t--){
       solve(); 
    }
	return 0;
}
