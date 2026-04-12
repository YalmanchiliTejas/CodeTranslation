#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int N;
    cin >> N;
    vector<int> s(N);
    for( int i = 0; i < N; ++i ) cin >> s[i];


    long long ans = 0;
    for( int C = 1; C < N; ++C ){  // C = A-B
        long long score = 0;
        vector<bool> isVisited(N, false);
        for( int k = 0;; ++k ){  // k*C + A = N-1
            int A = (N-1) - k*C;
            int B = A-C;
            if (A <= 0) break;  // A = (N-1) - k*C > 0 の条件
            if (B <= 0) break;  // B = A-C = (N-1)-(k-1)*C > 0 の条件

            if( isVisited[k*C] ) break;
            isVisited[k*C] = true;
            score += s[k*C];
            
            if( isVisited[A] ) break;
            isVisited[A] = true;
            score += s[A];

            ans = max(ans, score);
        }
    }
    cout << ans << endl;

    return 0;
}