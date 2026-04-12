#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#include <queue>
#include <climits>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define put(a) cout<<a<<endl;
using namespace std;
typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int, int> P;

int h,w;
//stinrg a[101];
int main() {
    cin >> h >> w;
    vector<string> a(h);
    REP(i,h){
        cin >> a[i];
    }
    vector<bool> b(h);
    vector<bool> c(w);
    REP(i,h){
        bool flag = true;
        REP(j,w){
            if(flag&&a[i][j]=='.'){
            }else{
                flag=false;
            }
            b[i]=flag;
        }
    }
    REP(i,w){
        bool flag = true;
        REP(j,h){
            if(flag&&a[j][i]=='.'){
            }else{
                flag=false;
            }
            c[i]=flag;
        }
    }
    /*REP(i,h){
        put(b[i]);
    }
    REP(i,h){
        put(c[i]);
    }*/
    vector<string> res;
    REP(i, h){
        if(!b[i]){
            string d = "";
            REP(j,w){
                if(!c[j]){
                    d += a[i][j];
                }
            }
            res.push_back(d);
        }
    }
    REP(i,res.size()){
        put(res[i]);
    }
    //
    //put(res);
    //
    //put(res.size());
    //put(h);
    return 0;
}
