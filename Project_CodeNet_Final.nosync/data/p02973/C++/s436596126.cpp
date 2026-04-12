///usr/bin/g++ -O2 $0 -o ${0%.cpp} && echo "----------" && ./${0%.cpp}; exit;
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

int n; 

int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    vector<int> v(n + 1, 1e9); 

    for(int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        *upper_bound(v.begin(), v.end(), -a) = -a; 
    }

    int ans = lower_bound(v.begin(), v.end(), 1e9) - v.begin(); 

    printf("%d\n", ans);
}