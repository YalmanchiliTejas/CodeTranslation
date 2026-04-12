#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(){
    long long N;
    cin >> N;
    vector<long long> s(N);
    for(long long i=0; i<N; i++)
        cin >> s[i];

    long long ans = 0;
    for(long long C=1; C<N-1; C++){
        long long cur = 0;
        long long l = 0, r = N-1;
        for(long long k=0; k<=N; k++){
            bool ok = true;
            for(long long i=1; i<=2; i++){
                if((2*k+i)*C==N-1)
                    ok = false;
            }
            if(!ok) break;
            l += C;
            r -= C;
            if(r <= 0) break;
            if(C >= r) break;
            cur += s[l] + s[r];
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}