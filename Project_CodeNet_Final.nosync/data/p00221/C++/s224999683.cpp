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


const string FIZZBUZZ = "FizzBuzz";
const string FIZZ = "Fizz";
const string BUZZ = "Buzz";
bool used[1001];
int cur;
int remains;
int m, n;

void init() {
    fill( used, used+1001, false );
    remains = m;
    cur = 0;
}

VI get() {
    VI res;
    for ( int i = 0; i < m; ++ i ) {
        if ( ! used[i] ) res.push_back(i);
    }
    return res;
}

void next() {
    do {
        cur = ( cur + 1 ) % m;
    } while ( used[cur] );
}

bool check( int real, string s ) {
    if ( real % 15 == 0 ) {
        if ( s != FIZZBUZZ ) return false;
    } else if ( real % 5 == 0 ) {
        if ( s != BUZZ ) return false;
    } else if ( real % 3 == 0 ) {
        if ( s != FIZZ ) return false;
    } else {
        OSS oss;
        oss << real;
        if ( s != oss.str() ) return false;
    }
    return true;
}

void output() {
    VI v = get();
    for ( VI::iterator it_i = v.begin(); it_i != v.end(); ++ it_i ) {
        cout << (*it_i+1);
        if ( it_i + 1 != v.end() ) cout << " ";
    }
    cout << endl;
}

int main() {
    while ( cin >> m >> n && m ) {
        init();
        for ( int i = 0; i < n; ++ i ) {
            int real = i + 1;
            string s;
            cin >> s;
            if ( remains == 1 ) continue;
            if ( ! check( real, s ) ) {
                used[cur] = true;
                remains --;
            }
            next();
        }
        output();
    }
    return 0;
}