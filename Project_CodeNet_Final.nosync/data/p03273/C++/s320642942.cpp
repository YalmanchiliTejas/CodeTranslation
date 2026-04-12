#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    int h, w;
    cin >> h >> w;
    vector<vector<char> > a(h, vector<char>(w, 0));
    vector<bool> row_flg(h, false);
    vector<bool> col_flg(w, false);
    for (auto i=0;i<h;++i) {
        for(auto j=0;j<w;++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                row_flg[i] = true;
                col_flg[j] = true;
            }
        }
    }

    for(auto i=0;i<h;++i) {
        if (row_flg[i]) {
            for(auto j=0;j<w;++j) {
                if(col_flg[j]) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}
