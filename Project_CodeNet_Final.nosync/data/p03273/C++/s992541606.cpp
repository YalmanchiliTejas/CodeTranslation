#include<algorithm>
#include<string>
#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
 
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
 
 
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    int k=0;
    REP(i,h-k){
        int count = 0;
        cin >> a[i];
        REP(j,w){
            if(a[i][j] == '.'){
                count++;
            }
        }
        if(count == w){
            i--;
            k++;
        }
    }
    int t=0;
    REP(j,w-t){
        int count =0;
        REP(i,h-k){
            if(a[i][j]=='.'){
                count++;
            }
        }
        if(count == h-k){
            REP(i,h-k){
                a[i].erase(a[i].begin()+j);
            }
            j--;
            t++;
        }
    }
    REP(i,h-k){
            cout << a[i] << endl;
    }


    
    return 0;
}