#include<bits/stdc++.h>
#define F first
#define S second
#define endl '\n'
#define lcm( a, b ) ((a)/__gcd(a,b)*(b))
#define MP make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<int, P> i_P;
typedef pair< LL, LL > L_P;

const int INF = INT_MAX;
const int MIN = INT_MIN;
const LL LINF = LLONG_MAX;
const int MOD = 1000000000 + 7;
const int SIZE = 100005;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string fb[10005];
    for( int i = 1; i <= 10000; ++i ) {
        if( i % 3 == 0 && i % 5 == 0 ) fb[i] = "FB";
        else if( i % 3 == 0 ) fb[i] = "F";
        else if( i % 5 == 0 ) fb[i] = "B";
        else {
            string t;
            int tmp = i;
            while( tmp != 0 ) {
                char c = ( tmp % 10 ) + '0';
                t += c;
                tmp /= 10;

            }
            reverse( all(t) );
            fb[i] = t;

        }
    }

    bool player[1005];

    while( true ) {
        for( int i = 0; i < 1005; ++i ) player[i] = true;

        int m, n;
        cin >> m >> n;
        if( m == 0 && n == 0 ) break;

        int turn = 1;
        int p = m;
        for( int i = 1; i <= n; ++i ) {
            string s;
            cin >> s;
            
            if( p == 1 ) continue;
            if( s == "FizzBuzz" ) {
                if( fb[i] != "FB" ) {
                    --p;
                    player[turn] = 0;

                }

            } else if( s == "Fizz" ) {
                if( fb[i] != "F" ) {
                    --p;
                    player[turn] = 0;

                }

            } else if( s == "Buzz" ) {
                if( fb[i] != "B" ) {
                    --p;
                    player[turn] = 0;

                }
                
            } else {
                if( fb[i] != s ) {
                    --p;
                    player[turn] = 0;

                }
            
            }
            ++turn;
            while( turn <= m && !player[turn] ) ++turn;

            if( turn > m ) {
                turn = 1;
                while( turn <= m && !player[turn] ) ++turn;

            }
        }
        
        for( int i = 1; i <= m; ++i ) {
            if( player[i] ) {
                if( p == 1 ) {
                    cout << i << endl;
                    break;

                } else {
                    cout << i << " ";

                }
                --p;
            }
        }

    }
    return 0;
}



