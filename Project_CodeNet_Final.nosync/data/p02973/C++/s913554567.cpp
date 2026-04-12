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
int A[100000+10];
vector<int> parent;

int solve(void) {
    parent.push_back(A[1]);
    for(int j = 2;j <= N;j++) {
        //cout<<upper_bound(parent,parent+N,A[j]) - parent<<endl;
        int index = upper_bound(parent.begin(),parent.end(),A[j]) - parent.begin();
        //cout<<parent.size()<<" "<<index<<endl;
        if(index + 1 > parent.size()) {
            parent.push_back(A[j]);
        } else {
            parent[index] = A[j];
        }
        //parent[(upper_bound(parent+1,parent+N+1,A[j]) - (parent+1))] = A[j];
    }

    cout<<parent.size()<<endl;
    return 0;
}

int main(void) {
    cin>>N;
 
    for(int i = 1;i <= N;i++) {
        cin>>A[i];
        A[i] = -1*A[i];
    }

    solve();

    return 0;
}



