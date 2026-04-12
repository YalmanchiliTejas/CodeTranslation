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

int N;
vector<Int> s;

int main(void) {
    cin>>N;

    for(int i = 0;i < N;i++) {
        Int x;
        cin>>x;
        s.push_back(x);
    }

    Int ans = 0;
    for(int d = 1;d <= N-1;d++) {
        Int score = 0;
        int left = 0;
        int right = N-1;
        
        while(1) {
            left += d;
            right -= d;
            if(left == right || right <= d || left-d == right)
                break;
            score += s[left]+s[right];
            ans = max(ans, score);
        }
    }

    cout<<ans<<endl;


    return 0;
}
