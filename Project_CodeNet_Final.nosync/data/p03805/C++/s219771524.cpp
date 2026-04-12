#include <bits/stdc++.h>
using namespace std;

int main() {
    int p[7] = {1, 2, 3, 4, 5, 6, 7};
    int N,M,i,a,b,c=0,x=0;
    cin >> N >> M;
    vector<vector<bool>> e(N, vector<bool>(N,0));

    for(i=0; i<M; i++) {
        cin >> a >> b;
        e.at(a-1).at(b-1) = 1;
        e.at(b-1).at(a-1) = 1;
    }

    do {
        for(i=0; i<N-1; i++) {
            if(!e.at(x).at(p[i]))
                break;
            x = p[i];
        }
        if(i==N-1)
            c++;
        x = 0;
    } while(next_permutation(p, p+N-1));

    cout << c << endl;
}