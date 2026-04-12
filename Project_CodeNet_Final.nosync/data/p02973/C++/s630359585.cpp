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

int main(void) {
    int N;
    cin>>N;
    vector<int> A;

    for(int i = 0;i < N;i++) {
        int a;
        cin>>a;
        A.push_back(-a);
    }

    vector<int> ans;
    ans.push_back(A[0]);

    for(int i = 1;i < N;i++) {
        int a = A[i];
        auto itr = upper_bound(ans.begin(),ans.end(),a);
        if(itr == ans.end())
            ans.push_back(a);
        else
            *itr = a;
    }

    cout<<ans.size()<<endl;

    return 0;
}
