#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;

    int ans=INT_MAX;

    for (int t = 0; t <= max(X, Y) * 2; t++) {
        int cur_cost = A * max(X - t / 2, 0) + B * max(Y - t / 2, 0) + t * C;
        if (ans >= cur_cost) {
            ans = cur_cost;
        } 
    }
    cout<<ans<<endl;
}