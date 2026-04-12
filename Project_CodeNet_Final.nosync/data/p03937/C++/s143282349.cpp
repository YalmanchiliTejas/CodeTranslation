#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
ios::sync_with_stdio(false);
std::cin.tie(nullptr);
ll h,w;
cin >> h >> w;
vector<string> stones(h);
ll cnt = 0;
for(ll i = 0; i < h; i++){
    cin >> stones[i];
    for(ll j = 0; j < w; j++){
        if(stones[i][j] == '#')
            cnt++;
    }
}
cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << endl;
}