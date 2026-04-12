#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<pair<int,int>> vp;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<bool>> vbb;
typedef pair<int,int> pi;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define REP(n, x) for(int i = n; i < x; i++)
#define REPN(n, x) for(int i = x; i >= n; i--)
#define REPVS(arr) for(auto &x : arr)
#define REPV(arr) for(auto x : arr)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(x) printf("%s\n", s.c_str())
#define F first
#define S second

const int INF = INT_MAX;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    si(n);
    if(n >= 30){
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}