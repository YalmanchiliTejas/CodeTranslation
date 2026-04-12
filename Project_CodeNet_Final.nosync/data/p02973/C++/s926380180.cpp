#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=2e5+5;
const int mod=1e9+7;
int a[maxm];
int b[maxm];
int n;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    multiset<int>s;
    s.insert(a[1]);
    for(int i=2;i<=n;i++){
        auto it=s.lower_bound(a[i]);//>=a[i]
        if(it==s.begin()){
            s.insert(a[i]);
        }else{
            it--;
            s.erase(it);
            s.insert(a[i]);
        }
//        cout<<i<<": ";
//        for(auto x:s){
//            cout<<x<<' ';
//        }
//        cout<<endl;
    }
    cout<<s.size()<<endl;
    return 0;
}
/*

*/
