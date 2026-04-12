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
    for(int i = 1;i < N;i++) {
        int left = 0;
        int right = N-1;
        Int score = 0;
        while(1) {
            left += i;
            right -= i;
            if(left == right || right <= i || left-i == right)
                break;

            score += s[left] + s[right];
            ans = max(ans,score);
        }
    }

    cout<<ans<<endl;

    return 0;
}
