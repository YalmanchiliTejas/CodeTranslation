#include<iostream>
using namespace std;

int main()
{
    int h, w;
    int i, j, count = 0;
    
    cin >> h >> w;
    
    char a[h][w];
    
    for(i = 0; i < h; i++) {
        for(j = 0; j < w; j++) {
            cin >> a[i][j];
            if(a[i][j] == '#') {
                count++;
            }
        }
    }
    
    if(count == h + w - 1) {
        cout << "Possible\n";
    } else {
        cout << "Impossible\n";
    }
    
    return 0;
}