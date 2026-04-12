#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>

typedef long long ll;

using namespace std;
int main() {
    string s;
    ll h,w;
    cin >> h >> w;
    vector<vector<char> > a(h, vector<char>(w));
    for (auto i=0; i<h; ++i){
        for (auto j=0; j<w; ++j){
            cin>>a[i][j];
        }
    }
    vector<int> x,y;
    for (auto i=0; i<h; ++i){
        bool con = false;
        for (auto j=0; j<w; ++j){
            if (a[i][j] == '#'){
                con = true;
                break;
            }
        }
        if(con) x.push_back(i);
    }
    
    for (auto j=0;j<w; ++j){
        bool con = false;
        for(auto it=x.begin(); it!=x.end(); ++it){
            if(a[*it][j]=='#'){
                con = true;
                break;
            }
        }
        if(con)y.push_back(j);
    }
    
    for(auto it=x.begin(); it!=x.end(); ++it){
        for(auto jt=y.begin(); jt!=y.end(); ++jt){
            cout << a[*it][*jt];
        }
        cout << endl;
    }
    return 0;
}