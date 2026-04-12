#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N;
int H[21];

int main(){
    cin>>N;
    rep(i,N) cin>>H[i];

    int ans=0;
    int maxh=0;
    rep(i,N){
        if(maxh<=H[i]){
            ans++;
            maxh=H[i];
        }
    }

    cout<<ans<<endl;
}