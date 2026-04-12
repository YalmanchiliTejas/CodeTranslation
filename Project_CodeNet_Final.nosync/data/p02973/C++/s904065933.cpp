#include <bits/stdc++.h>
using namespace std;
#define rep(i,m, n) for(int i=m; i<n; i++)
typedef long long ll;



int main(){
    int n; cin>>n;
    int a[n];
    rep(i,0,n) cin>>a[i];
    deque<int> v;

    rep(i,0,n){
        int b=lower_bound(v.begin(),v.end(),a[i])-v.begin();
        if(b==0){
            v.push_front(a[i]);
        }
        else{
            v[b-1]=a[i];
        }
    }
    cout<<v.size()<<endl;
}