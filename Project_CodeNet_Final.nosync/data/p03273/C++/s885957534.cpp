#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#define INF 1000000000
#define MOD 1000000007

using namespace std;

int main()
{
    string map[105];
    string cmp;
    int h, w;

    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        cin >> map[i];
    }

    for(int i = 0; i < w; i++) {
        cmp += '.';
    }

    for(int i = 0; i < h; i++) {

        if(map[i] != cmp) {
            for (int j = 0; j < w; j++) {
                int k;
                k = 0;
                while (map[k][j] == '.' && k < h) {
                    k++;
                }

                if (k < h) {
                    cout << map[i][j];
                }
            }

            cout << endl;
        }
    }




    return 0;
}
