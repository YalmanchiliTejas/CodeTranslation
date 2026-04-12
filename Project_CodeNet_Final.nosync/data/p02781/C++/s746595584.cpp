#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <map>

using namespace std;

int main(void) {
    string N;
    int K;
    cin >> N >> K;
    
    if(K == 1) {
        cout << 9 * (N.size()-1) + stoi(N.substr(0, 1)) << endl;
    } else if(K == 2) {
        int64_t ans = 0;
        for(int i=2; i<N.size(); i++) {
            ans += 9 * 9 * (i-1);
        }
        ans += (stoi(N.substr(0, 1)) - 1) * 9 * (N.size()-1);
        string cp = N;
        for(int i=1; i<cp.size(); i++) {
            cp[i] = '0';
        }
        for(int i=1; i<cp.size(); i++) {
            for(int j=1; j<10; j++) {
                cp[i] = '0'+j;
                if(cp <= N) {
                    ++ans;
                }
                cp[i] = '0';
            }
        }
        cout << ans << endl;
    } else {
        if(N.size() < 3) {
            cout << 0 << endl;
            return 0;
        }
        int64_t ans = 0;
        for(int i=3; i<N.size(); i++) {
            ans += 9 * 9 * 9 * (i-1) * (i-2) / 2;
        }
        ans += (stoi(N.substr(0, 1)) - 1) * 9 * 9 * (N.size()-1) * (N.size()-2) / 2;
        string cp = N;
        for(int i=1; i<cp.size(); i++) {
            cp[i] = '0';
        }
        for(int i=1; i<cp.size(); i++) {
            for(int j=i+1; j<cp.size(); j++) {
                for(int k=1; k<10; k++) {
                    for(int l=1; l<10; l++) {
                        cp[i] = '0' + k;
                        cp[j] = '0' + l;
                        if(cp < N) {
                            ++ans;
                        }
                        cp[i] = '0';
                        cp[j] = '0';
                    }
                } 
            }
        }
        cout << ans << endl;
    }
    return 0;
}
