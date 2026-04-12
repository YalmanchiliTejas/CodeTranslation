#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int N;
    int H[20];
    cin>>N;
    rep(i,N) cin>>H[i];
    int ans=1;
    int temp=H[0];
    rep(i,N-1){
        if(temp<=H[i+1]) {
            ans++;
            temp=H[i+1];
        }
    }
    cout<<ans<<endl;
    return 0;
}