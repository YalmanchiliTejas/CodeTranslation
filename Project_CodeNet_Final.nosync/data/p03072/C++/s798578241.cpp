#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> Hs(N, 0);
    for (auto &h : Hs) cin >> h;
    int rec = 0;
    int count = 0;
    for (auto h: Hs){
        if (h >= rec){
            ++count;
            rec = h;
        }
    }
    cout << count << endl;
    return 0;
}