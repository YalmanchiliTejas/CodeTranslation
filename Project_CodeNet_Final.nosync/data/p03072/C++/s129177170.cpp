#include <bits/stdc++.h>

int main(){
    using namespace std;
    int N; cin >> N;
    int highest = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int h; cin >> h;
        if(h>=highest) cnt++;
        highest = max(highest, h);
    }
    cout << cnt << endl;
    
}
