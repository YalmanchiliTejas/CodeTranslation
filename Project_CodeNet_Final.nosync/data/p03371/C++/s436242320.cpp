#include <bits/stdc++.h>
using namespace std;

template<typename T>
void printmatrix(vector<vector<T> > ar){
    for (int i = 0; i < (int)ar.size(); i++) {
        for (int j = 0; j < (int)ar.size(); j++) {
            cout << ar[i][j];
        }
        cout << endl;
    }
}

template<typename T>
void printvector(vector<T> vec){
    for (int i = 0; i < (int)vec.size(); i++) {
        cout << vec[i] << endl;
    }
}


int main(int argc, char const* argv[])
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int total=0;
    while ((x > 0) || (y > 0)) {
        if ( ( (a >= 2*c) && (x > 0) ) || ( (b >= 2*c) && (y > 0) ) || ( (a+b >= 2*c) && (x > 0) && (y > 0) )) {
            total += 2*c;
            x -= 1;
            y -= 1;
        }else if (x > 0) {
            total += a;
            x--;
        }else if (y > 0){
            total += b;
            y--;
        }
    }

    cout << total << endl;
    return 0;
}