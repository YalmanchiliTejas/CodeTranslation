#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

static const int INTINF = (2147483647);
static const ll LLINF = (9223372036854775807);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;

namespace Printer{
    template<class T>
    void print(T x){
        cout << x << endl;
    }

    template<class T>
    void print(T x, T y){
        cout << x << "," << y << endl;
    }

    template<class T>
    void print(vector<T> v){
        rep(i, v.size()){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    template<class T>
    void print(vector<vector<T> > vv){
        rep(i, vv.size()){
            rep(j, vv[i].size()){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void print(pair<int, int> p){
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
};
using namespace Printer;

//--global--//



//----------//

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//

    int mi = -1, ma = -1;
    int n;
    cin >> n;
    vector<int> v;
    rep(i, n){
        int a;
        cin >> a;
        int index = lower_bound(ALL(v), a) - v.begin() - 1;
        //cout << index << endl;
        if(index == -1){
            v.insert(v.begin(), a);
        }
        else{
            v[index] = a;
        }
    }
    //print(v);
    print(v.size());
    
    return 0;
}
