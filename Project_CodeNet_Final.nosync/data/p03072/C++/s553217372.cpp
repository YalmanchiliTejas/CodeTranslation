#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    int maxi = 0,cnt = 0;
    rep(i,0,N){
        int a;
        cin >> a;
        if(a >= maxi){
            maxi = a;
            cnt++;
        }
    }
    cout << cnt << endl;
}