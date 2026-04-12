#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    int maxh; 
    int H,cnt;

    maxh = 0;
    cnt = 0;

    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> H;
        if(maxh <= H) {
            cnt++;
            maxh = H;
        }
    }

    cout << cnt << endl;
    return 0;
}
