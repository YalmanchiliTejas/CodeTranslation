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

vector<int> A,color;

int N;

int solve(void) {
    color.push_back(A[0]);
    for(int i = 1;i < N;i++) {
        auto iter = upper_bound(color.begin(),color.end(),A[i]);
        if(iter == color.end()) {
            color.push_back(A[i]);
        } else {
            *iter = A[i];
        }
    }

    return color.size();
}

int main(void) {
    cin>>N;

    for(int i = 0;i < N;i++) {
        int a;
        cin>>a;
        A.push_back(-a);
    }

    cout<<solve()<<endl;

    return 0;
}
