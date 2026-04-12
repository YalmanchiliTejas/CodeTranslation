#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,m=0,i,H,c=0;
    cin >> N;

    for(i=0; i<N; i++) {
        cin >> H;
        if(H >= m)
            c++;
        m = max(m,H);
    }
    
    cout << c << endl;
}