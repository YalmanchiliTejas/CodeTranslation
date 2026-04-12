#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> A(h);
    for (auto &a: A)
        cin >> a;
    
    int cnt = 0;
    for (const auto &a: A)
        cnt += count(a.begin(), a.end(), '#');

    puts(cnt == h + w - 1 ? "Possible" : "Impossible");
}