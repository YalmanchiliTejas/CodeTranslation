#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const auto INF = (ll)1e9;
using v = vector<ll>;
using m = map<int,int>;
using vv = vector<v>;

int main(){
    int x,y,z;
    cin >> x >> y >>z;
    auto ans = x/(y+z);
    auto d   = ans*(y+z);
    cout <<(x-d>=z?ans:ans-1);
}
