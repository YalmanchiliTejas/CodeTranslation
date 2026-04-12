#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

typedef pair <int, int> PII;
typedef stack <PII> STACK;

int main() {
    int n;
    while ( cin >> n ) {
        if ( n == 0 ) break;
        STACK S;
        for ( int i = 0; i < n; ++ i ) {
            int g;
            cin >> g;
            if ( i % 2 == 0 ) {
                if ( S.empty() ) {
                    S.push( PII( 1, g ) );
                } else {
                    PII last = S.top();
                    if ( last.second != g ) {
                        S.push( PII( 1, g ) );
                    } else {
                        S.pop();
                        S.push( PII( last.first + 1, g ) );
                    }
                }
            } else {
                PII last = S.top();
                if ( last.second != g ) {
                    int con = 0;
                    while ( last.second != g ) {
                        S.pop();
                        con += last.first;
                        if ( S.empty() ) break;
                        last = S.top();
                    }
                    S.push( PII( con + 1, g ) );
                } else {
                    S.pop();
                    S.push( PII( last.first + 1, g ) );
                }
            }
        }
        
        int answer = 0;
        while ( ! S.empty() ) {
            PII state = S.top();
            S.pop();
            if ( state.second == 0 ) {
                answer += state.first;
            }
        }
        cout << answer << endl;
    }
    return 0;
}