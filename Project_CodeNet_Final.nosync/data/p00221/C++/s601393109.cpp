#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N;

    while ( cin >> M >> N, M != 0 && N != 0 ) {
        bool flag[1005] = {};
        int jb = 0;
        int cnt = 1;
        int d = 0;
        bool lock = false;
        while ( cnt <= N ) {
            string S;
            cin >> S;
            if ( !lock ) {
                if ( S == "FizzBuzz" ) {
                    if ( cnt % 15 != 0 ) {
                        flag[jb] = true;
                        d++;
                    }
                } else if ( S == "Fizz" ) {
                    if ( cnt % 3 != 0 || cnt % 15 == 0 ) {
                        flag[jb] = true;
                        d++;
                    }
                } else if ( S == "Buzz" ) {
                    if ( cnt % 5 != 0 || cnt % 15 == 0 ) {
                        flag[jb] = true;
                        d++;
                    }
                } else {
                    int val = atoi(S.c_str());
                    if ( val != cnt || cnt % 3 == 0 || cnt % 5 == 0 ) {
                        flag[jb] = true;
                        d++;
                    }
                }
                if ( d == M - 1 ) {
                    lock = true;
                }
                (jb += 1) %= M;
                while ( flag[jb] ) {
                    (jb += 1) %= M;
                }
            }
            cnt++;
        }
        vector < int > ans;
        for ( int i = 0; i < M; i++ ) {
            if ( !flag[i] ) {
                ans.push_back(i + 1);
            }
        }
        cout << ans[0];
        for ( int i = 1; i < ans.size(); i++ ) {
            cout << " " << ans[i];
        }
        cout << endl;
    }
    return ( 0 );
}

