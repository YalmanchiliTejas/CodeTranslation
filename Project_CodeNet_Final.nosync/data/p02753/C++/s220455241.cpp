
#include <bits/stdc++.h>

using namespace std;
using LL = long long;
const int N = 1024;
const int INF = INT32_MAX - 1;
const double EPS = 1E-9;

int a[N];
int n, m;

int main() {
    ios_base::sync_with_stdio(false);

#ifdef CF_DEBUG
    freopen("../cf/input.txt","r",stdin);
#endif
    string s;
    cin >> s;
    if(s == "AAA" || s== "BBB"){
        cout<<"No";
    }else{
        cout<<"Yes";
    }
    return 0;
}