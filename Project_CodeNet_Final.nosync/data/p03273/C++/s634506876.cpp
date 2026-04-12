#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W));

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                a[h][w] = 0;
            }
            else
            {
                a[h][w] = 1;
            }
        }
    }

    vector<int> vline(W, 0), hline(H, 0);

    for (int w = 0; w < W; w++)
    {
        for(int h = 0; h < H; h++){
            if(h == 0){
                vline[w] = a[0][w];
            } else {
                vline[w] *= a[h][w];
            }
        }
    }

    for (int h = 0; h < H; h++)
    {
        for(int w = 0; w < W; w++){
            if(w == 0){
                hline[h] = a[h][0];
            } else {
                hline[h] *= a[h][w];
            }
        }
    }
    
    for(int i = 0; i < H; i++){
        if(hline[i] == 0){
            for(int j = 0; j < W; j++){
                if(vline[j] == 0){
                    cout << ((a[i][j] == 0) ? '#' : '.' );
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}
