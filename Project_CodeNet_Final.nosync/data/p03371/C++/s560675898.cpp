#include <iostream>
#include "bits/stdc++.h"
using namespace std;
#define print(x) cout<<x<<endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a) for(int i=0;i<a;i++)
#define printall(n,array) {for(int i=0;i<n;i++){cout<<array[i]<<" ";}cout<<endl;}
#define U() cout<<endl;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<int, PI> V;
typedef vector<int> VE;
const ll mod = 1000000007; //10^9+7

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    int min_ = min(x, y);
    if(a + b < 2 * c){
        ans += min_ * (a + b);
    }else{
        ans += min_ * 2 * c;
    }
    if((x - min_) * a + (y - min_) * b < (x - min_) * 2 * c + (y - min_) * 2 * c){
        ans += (x - min_) * a + (y - min_) * b;
    }else{
        ans += (x - min_) * 2 * c + (y - min_) * 2 * c;
    }
    print(ans);
}