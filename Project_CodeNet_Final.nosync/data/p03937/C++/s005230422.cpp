#include <iostream>
#include <fstream>
using namespace std;
int n, m;
char a[10][10];
int dem = 0;
int main()
{
    //freopen("vao.inp","r",stdin);
    int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= n; i++)
        for ( int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if ( a[i][j] == '#' ) dem++;
        }
    //cout << dem << '\n';
    int x, y;
    x = 1; y = 1;
    for ( int i = 1; i <= n; i++) {
        if ( x > m ) break;
        while ( a[i][x] == '#' ) {
            dem--;
            x++;
        }
        x--;
    }
    if ( dem ) cout << "Impossible";
        else cout << "Possible";
    //cout << "Hello world!" << endl;
    return 0;
}
