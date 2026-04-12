#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    long long int n;
    cin >> n;

    vector< long long int > v;

    for ( long long int i = 0; i < n; i++ ) {

        long long int in;
        cin >> in;

        /*
        if ( v.size() == 0 ) {
            v.push_back( in );
            continue;
        }
        */

        decltype(v)::iterator it = std::upper_bound( v.begin(), v.end(), -in );
        if ( it != v.end() ) {
            *it = -in;
        } else {
            v.insert( v.end(), -in );
        }

    }

    cout << v.size() << endl;

    return 0;

}
