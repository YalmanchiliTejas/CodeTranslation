#include<bits/stdc++.h>
#include<vector>
#define V vector
#define VI vector<int>
#define VVI vector<vector<int>>
#define rep(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007

using namespace std;


int main(void){
    int n;
    cin>>n;
    VI A(n);
    rep(i,n)cin>>A[i];
    deque<int> d;
    rep(i,n){
        int p=lower_bound(d.begin(),d.end(),A[i])-d.begin();
        if(p==0){
            d.push_front(A[i]);
        }else{
            d[p-1]=A[i];
        }
        
    }
    int ans=d.size();
    cout<<ans<<endl;

}

