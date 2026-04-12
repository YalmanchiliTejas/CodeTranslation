#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long H, W;
    cin >> H >> W;
    unsigned long a{0};
    for(unsigned long i = 0; i < H; ++i){
        string s;
        cin >> s;
        a += count(s.begin(), s.end(), '#');
    }
    puts(a == H + W - 1 ? "Possible" : "Impossible");
    return 0;
}