#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <utility>
#include <list>
#include <climits>
#include <bitset>
#include <numeric>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, n) for(auto i = (n).begin(); i != (n).end(); i++)
#define in_arr(type, a, n) copy_n(istream_iterator<type>(cin), n, (a).begin());
#define ll long long int

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    in_arr(string, s, h);
    vector<bool> col(h, false), row(w, false);
    rep(i, h){
        rep(j, w){
            if(s[i][j] == '#'){
                col[i] = true;
                break;
            }
        }
    }
    rep(i, w){
        rep(j, h){
            if(s[j][i] == '#'){
                row[i] = true;
                break;
            }
        }
    }
    
    rep(i, h){
        if(!col[i]){
            continue;
        }
        rep(j, w){
            if(!row[j]){
                continue;
            }
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}
