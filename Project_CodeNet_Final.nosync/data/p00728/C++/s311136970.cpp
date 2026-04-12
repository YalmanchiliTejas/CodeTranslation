#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>

#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define vsort(v) sort(v.begin(),v.end())
#define asort(a,n) sort(a, a + n)
#define vi vector<int>
#define vd vector<double>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int N;
    int ans;
    int cnt;
    vi vec(100);
    while(true){
        vec.assign(100, -1);
        ans = 0;
        cnt = 0;
        cin >> N;
        if(N == 0) return 0;
        rep(i, N){
            cin >> vec[i];
        }
        vsort(vec);
        REP(i, 101 - N, 99){
            ans += vec[i];
            cnt++;
        }
        cout << (int)(ans / cnt) << endl;
    }


    return 0;
}