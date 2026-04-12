#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007LL;
int main(){
    int n;
    cin >> n;
    int h[n];
    int tem;
    int ans = 0;
    rep(i,n){
        cin >> h[i];
        if(i == 0){
            tem = h[0];
            ans++;
        }
        else{
            if(tem <= h[i]){
                ans++;
                tem = h[i];
            }
        }
    }
    cout << ans << endl;
}
