#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<queue>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
ll dx[4] = {1,0,0,-1};
ll dy[4] = {0,1,-1,0};

#define ARRAY_MAX 1005
int a[ARRAY_MAX];

int main(){

    int n;
    while(cin >> n,n){

        int maxi = -1;
        int mini = INF;
        vector<int> a(n);
        REP(i,n){
            cin >> a[i];
        }
        VSORT(a);
        int sum = 0;
        for(int i = 1;i < n-1;i++){
            sum += a[i];
        }
        cout << sum/(n-2) << endl;
    }
    
    
    return 0;
}
