#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;
    unsigned long max{0}, ans{0};
    for(unsigned long i = 0, h; i < N; ++i){
        cin >> h;
        if(max <= h){
            ++ans;
            max = h;
        }
    }
    cout << ans << endl;
    return 0;
}