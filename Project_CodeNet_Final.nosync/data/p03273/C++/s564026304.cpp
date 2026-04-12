#include <bits/stdc++.h>
using namespace std;
int main()
{/// Standing in The hall of Fame
    ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL);
    int h , w , k , x[105]{} , y[105]{};
    char g[105][105];
    cin >> h >> w;
    for(int i = 1 ; i <= h ; i++)
        for(int j = 1 ; j <= w ; j++)
            cin >> g[i][j];
    for(int i = 1 ; i <= h ; i++){
        k = 1;
        for(int j = 1 ; j <= w ; j++)
            if(g[i][j] == '#')k = 0;
        x[i] = k;
    }
    for(int i = 1 ; i <= w; i++){
        k = 1;
        for(int j = 1 ; j <= h ; j++)
            if(g[j][i] == '#')k = 0;
        y[i] = k;
    }
    //cout << "==========================\n";
    for(int i = 1 ; i <= h ; i++){
        if(x[i])continue;
        for(int j = 1; j <= w ; j++){
            if(y[j])continue;
            cout << g[i][j];
        }
        cout << "\n";
    }
    return 0;
}
