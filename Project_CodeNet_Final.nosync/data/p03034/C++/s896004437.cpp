#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <set>
#include <cmath>
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b+1;i++)
#define Per(i,b,a) for(int i=b;i>=a;i--)

ll solve(ll *s, int c,int N){
    ll ans = 0;
    ll temp = 0;
    int left = 0;
    int right = N-1;
    while(true){
        temp += s[left] + s[right];
        ans = max(temp,ans);
        left += c;
        right -= c;
        if(right == left || right == left-c) break;
        if(right<c) break; 
    }
    return ans;
}

int main(){
    int N;
    cin>>N;
    ll *s = new ll[N];
    rep(i,N) cin>>s[i];
    ll ans = 0;
    Rep(c,1,N-1){
        // cout<<c<<" "<<solve(s,c,N)<<endl;
        ans = max(ans,solve(s,c,N));
    }
    // cout<<endl;
    cout<<ans<<endl;
    delete[] s;
    return 0;
}