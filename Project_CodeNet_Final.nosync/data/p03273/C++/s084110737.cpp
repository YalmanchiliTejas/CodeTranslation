#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>


using namespace std;
typedef long long int ll;


int main() {
    ll H, W;
    cin >> H >> W;
    vector< vector<char> > a(H, vector<char>(W));
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> a[i][j];
        }
    }

    vector< vector<char> > b;
    ll r = 0;
    for(int i=0; i<H; i++) {
        if (count(a[i].begin(), a[i].end(), '#') > 0) {
            //cout << "push" << endl;
            b.push_back(a[i]); 
        } else {
            r++;
        }
    }
/*
    for (size_t i = 0; i < H - r; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
            cout << b[i][j];
        }
        cout << endl;
    }
*/
    vector<int> index;
    for(int i=0; i<W; i++) {
        bool flag = true;
        for(int j=0; j<H-r; j++) {
            if (b[j][i] == '#') {
                flag = false;
            }
        }
        if (flag) {
            index.push_back(i);
        }
    }
    /*
        for (auto x : index )
        {
            cout << x;
        }
        cout << endl;
        */

    for (size_t i = 0; i < H - r; i++)
    {
        for (size_t j = 0; j < W; j++)
        {   
            if (!(count(index.begin(), index.end(), j))) {
               cout << b[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}