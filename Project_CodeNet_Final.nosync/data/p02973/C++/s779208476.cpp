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
vector<int> A;

void solve(void) {
    vector<int> LDS;

    LDS.push_back(A[1]);
    for(int i = 2;i <= N;i++) {
        vector<int>::iterator it = upper_bound(LDS.begin(),LDS.end(),A[i]);
        if(it == LDS.end()) {
            LDS.push_back(A[i]);
        } else {
            *it = A[i];
        }
    }

    cout<<LDS.size()<<endl;

    return;
}

int main(void) {
    cin>>N;

    A.push_back(1);
    for(int i = 0;i < N;i++) {
        int a;
        cin>>a;
        a = -1*a;
        A.push_back(a);
    }

    solve();

    return 0;
}



