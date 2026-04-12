#include <iostream>

using namespace std;

char M[13][13];
bool p[13][13];

int main() {

    ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> M[i][j];
        }
    }

    if(M[1][1] == '#')
        p[1][1] = 1;

    for(int I = 1; I <= n; I++) {
        for(int J = 1; J <= m; J++) {
            if(I == 1 && J == 1)
                continue;
            if(M[I][J] == '#')
                p[I][J] = p[I-1][J]|p[I][J-1];
        }
    }

    for(int I = 1; I <= n; I++) {
        for(int J = 1; J <= m; J++) {
            if(M[I][J] == '#' && p[I][J] == false) {
                cout << "Impossible";
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(M[i][j] != '#')
                continue;
            if(M[i][j+1] == '#' && M[i+1][j] == '#') {
                cout << "Impossible";
                return 0;
            }
        }
    }

    cout << "Possible";

    return 0;
}
