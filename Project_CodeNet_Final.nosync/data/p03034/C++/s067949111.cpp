#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

vector<Int> s;
int N;

int main(void) {
    cin>>N;

    for(int i = 0;i < N;i++) {
        Int t;
        cin>>t;
        s.push_back(t);
    }

    Int ans = 0;
    for(int c = 1;c < N;c++) {
        if((N-1) % c == 0) {
            Int score = 0;
            int left = 0;
            int right = N-1;
            for(;left < right; left += c,right -= c) {
                score += s[left]+s[right];

                ans = max(ans, score);
            }

        } else {
            Int score = 0;
            int left = 0;
            int right = N-1;
            for(; left < N-1 && right > c;left += c, right -= c) {
                score += s[left]+s[right];
                ans = max(ans, score);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
