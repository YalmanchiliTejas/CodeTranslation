#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

typedef istringstream ISS;
typedef ostringstream OSS;
typedef vector<string> VS;
typedef int INT;
typedef vector<INT> VI;
typedef vector<VI> VVI;
typedef pair <INT, INT> II;
typedef vector <II> VII;

template<class T> ostream& operator << ( ostream& os, vector<T> v ) {
    for ( typename vector<T>::iterator it_i = v.begin(); it_i != v.end(); ++it_i ) {
        os << *it_i << ", ";
    }
    return os;
}


int LC[10][10];
int L[10][10]; 
int F[10][10]; 

void init() {
    for ( int i = 0; i < 10; ++ i ) {
        for ( int j = 0; j < 10; ++ j ) {
            L[i][j] = LC[i][j];
            F[i][j] = 0;
        }
    }
}

void input() {
    for ( int i = 0; i < 10; ++ i ) {
        for ( int j = 0; j < 10; ++ j ) {
            cin >> LC[i][j];
        }
    }
}

void output() {
    for ( int i = 0; i < 10; ++ i ) {
        for ( int j = 0; j < 10; ++ j ) {
            cout << F[i][j];
            if ( j + 1 < 10 ) cout << " ";
        }
        cout << endl;
    }
}

void flip( int r, int c ) {
    F[r][c] = 1;
    L[r][c] = !L[r][c];
    if ( r - 1 >= 0 ) L[r-1][c] = !L[r-1][c];
    if ( r + 1 < 10 ) L[r+1][c] = !L[r+1][c];
    if ( c - 1 >= 0 ) L[r][c-1] = !L[r][c-1];
    if ( c + 1 < 10 ) L[r][c+1] = !L[r][c+1];
}

bool solve( int r ) {
    if ( r >= 10 ) {
        for ( int i = 0; i < 10; ++ i ) {
            if ( L[r-1][i] == 1 ) return false;
        }
        return true;
    }
    if ( r == 0 ) {
        for ( int i = 0; i < (1<<10); ++ i ) {
            init();
            for ( int j = 0; j < 10; ++ j ) {
                if ( i & ( 1 << j ) ) flip( r, j );
            }
            if ( solve( r + 1 ) ) return true;
        }
        return 0;
    } else if ( r < 10 ) {
        for ( int i = 0; i < 10; ++ i ) {
            if ( L[r-1][i] ) {
                F[r][i] = 1;
                flip( r, i );
            }
        }
        if ( solve( r + 1 ) ) return true;
    }

    return false;
}

int main() {
    int n;
    while ( cin >> n ) {
        for ( int i = 0; i < n; ++ i ) {
            input();
            solve( 0 );
            output();
        }
    }
    return 0;
}