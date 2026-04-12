#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    ll n,x; cin>>n>>x;
    ll ans = 0;
    vector<ll[2]>dic(n+1);
    dic[0][0] = dic[0][1] = 1;
    for(int i = 1; i <= n; i++){
        dic[i][0] = dic[i-1][0]*2+1;
        dic[i][1] = dic[i-1][1]*2+3;
    }
    ll ptr = n;
    while(1){
        if(ptr == 0){
            ans++;
            break;
        }
        if(x == 1){
            break;
        }
        if(x > 1 && x <= dic[ptr][1]/2){
            ptr--;
            x--;
            continue;
        }
        if(x == dic[ptr][1]/2+1){
            ans+=dic[ptr-1][0]+1;
            break;
        }
        if(x > dic[ptr][1]/2+1 && x < dic[ptr][1]){
            ans+=dic[ptr-1][0]+1;
            x-=dic[ptr][1]/2+1;
            ptr--;
            continue;
        }
        if(x == dic[ptr][1]){
            ans += dic[ptr][0];
            break;
        }
    }
    cout << ans << endl;
}
