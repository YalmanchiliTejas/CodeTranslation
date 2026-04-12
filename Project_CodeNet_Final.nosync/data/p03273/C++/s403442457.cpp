#include<algorithm>
#include<climits>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<vector>

#define lint long long
#define REP(i, x, n) for(int i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())
#define IINF INT_MAX
#define LLINF LLONG_MAX

using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h){
        cin >> a[i];
    }
    rep(i, h){
        bool flag = true;
        rep(j, w){
            if(a[i][j] != '.'){
                flag = false;
                break;
            }
        }
        if(flag){
            a.erase(a.begin() + i);
            i--;
            h--;
        }
    }
    rep(j, w){
        bool flag = true;
        rep(i, h){
            if(a[i][j] != '.'){
                flag = false;
                break;
            }
        }
        if(flag){
            rep(i, h){
                a[i].erase(a[i].begin() + j);
            }
            j--;
            w--;
        }
    }
    rep(i, h){
        cout << a[i] << endl;
    }
    return 0;
}