#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;

int N,K;

int main(){
    cin>>N>>K;
    
    ll ans=0;
    repn(b,N){
        ans+=N/b*max(0,b-K);
        ans+=max(0,N%b-K+1);
    }
    if(K==0) ans-=N;

    cout<<ans<<endl;
}