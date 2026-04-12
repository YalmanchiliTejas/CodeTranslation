#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    rep(i,n)cin>>h[i];
    int ans=1;
    int maxh=h[0];
    for(int i=0;i<n-1;++i){
        if(h[i+1]>=maxh)ans++;
        maxh=max(maxh,h[i+1]);
    }
    cout<<ans<<endl;
}