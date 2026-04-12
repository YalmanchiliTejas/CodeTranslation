#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;


int main() {
    int N;
    cin>>N;
    int H[N];
    rep(i,N)cin>>H[i];
    
    int cnt=1;
    int mx=H[0];
    for(int i=1;i<N;i++){
        if(H[i]>=mx)cnt++;
        mx=max(mx,H[i]);
    }
    cout<<cnt<<endl;
}