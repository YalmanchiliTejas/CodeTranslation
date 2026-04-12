#include <bits/stdc++.h>
using namespace std;

int main(){
    int seat, person, gap;
    cin >> seat >> person >> gap;
    int filled = 0, ans = 0;
    seat -= gap;
    for(int i=0; filled<=seat; i++){
        filled += person + gap; 
        if(filled<=seat) ans++;
    }
    cout << ans << endl;
    return 0;
}