#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>

#define X first
#define Y second
#define vsort(v) sort((v).begin(), (v).end())
#define vrev(v) reverse((v).begin(), (v).end())


//INT_MAX
//INT_MIN
//LLONG_MAX
//LLONG_MIN
//DBL_MIN
//DBL_MAX
//LDBL_MIN
//LDBL_MAX

using namespace std;
using ll = long long;

int main(int argc, const char * argv[]) {
    int h, w;
    cin >> h >> w;
    string s;
    vector<string> v(h);
    vector<int> l, r;
    for (int i = 0; i < h; i++) {
        cin >> s;
        v[i] = s;
    }
    bool flag;
    for (int i = 0; i < h; i++) {
        flag = true;
        for (int j = 0; j < w; j++) {
            if (v[i][j] == '#') {
                flag = false;
                break;
            }
        }
        if (flag) {
            l.push_back(i);
        }
    }
    for (int i = 0; i < w; i++) {
        flag = true;
        for (int j = 0; j < h; j++) {
            if (v[j][i] == '#') {
                flag = false;
                break;
            }
        }
        if (flag) {
            r.push_back(i);
        }
    }
    
    int num = 0;
    if (l.size() == 0 && r.size() == 0) {
        for (int i = 0; i < h; i++) {
            cout << v[i] << endl;
        }
    }else{
        for (int i = 0; i < h; i++) {
            if (l.size() == 0 || i != l[num]) {
                for (int j = 0; j < w; j++) {
                    if (r.size() == 0) {
                        cout << v[i][j];
                    }else{
                        flag = true;
                        for (int k = 0; k < r.size(); k++) {
                            if (j == r[k]) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) {
                            cout << v[i][j];
                        }
                    }
                }
                cout << endl;
            }else{
                num++;
            }
        }
    }
}
