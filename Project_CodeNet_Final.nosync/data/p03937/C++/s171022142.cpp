#include <cstdio>

using namespace std;

int a[8][8];
char s[8][9];

int main() {
    int h, w, x = 0, y = 0, i, j;
    
    scanf("%d %d", &h, &w);
    
    for (i = 0; i < h; i++) scanf("%s", s[i]);
    
    if (s[0][0] != '#' || s[h - 1][w - 1] != '#') {
        puts("Impossible");
        
        return 0;
    }
    
    while (1) {
        a[x][y] = 1;
        
        if (x == h - 1 && y == w - 1) break;
        
        if (x == h - 1) {
            if (s[x][y + 1] != '#') {
                puts("Impossible");
                
                return 0;
            }
            
            y++;
        } else if (y == w - 1) {
            if (s[x + 1][y] != '#') {
                puts("Impossible");
                
                return 0;
            }
            
            x++;
        } else {
            if ((s[x][y + 1] == '#' && s[x + 1][y] == '#') || (s[x][y + 1] != '#' && s[x + 1][y] != '#')) {
                puts("Impossible");
                
                return 0;
            }
            
            if (s[x][y + 1] == '#') {
                y++;
            } else {
                x++;
            }
        }
    }
    
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (s[i][j] == '#' && a[i][j] == 0) {
                puts("Impossible");
                
                return 0;
            }
        }
    }
    
    puts("Possible");
    
    return 0;
}
