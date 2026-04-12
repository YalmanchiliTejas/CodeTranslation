#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++)
    {
        cin >> A[i];
    }

    int path = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == '#') path++;
        }
    }

    if(path == H + W - 1){
        cout << "Possible"<< endl;
    } else {
        cout << "Impossible" << endl;
    }
    
    return 0;
}
