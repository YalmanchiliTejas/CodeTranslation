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

const int max_n = 100000+10;
vector<int> L,A;

int main(void) {
    int N;
    cin>>N;

    for(int i = 0;i < N;i++) {
        int a;
        cin>>a;
        A.push_back(a);
    }

    L.push_back(-A[0]);

    for(int i = 1;i < N;i++) {
        int a = A[i];
        a *= -1;
        auto it = upper_bound(L.begin(),L.end(),a);
        if(it == L.end())
            L.push_back(a);
        else
            *it = a;
    }

    cout<<L.size()<<endl;


    return 0;
}
