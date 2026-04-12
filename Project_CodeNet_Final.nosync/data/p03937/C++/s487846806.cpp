#include <iostream>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    char a[10][10];
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
            if(a[i][j] == '#') ans++;
        }
    }
    if(ans == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}