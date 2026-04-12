#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> a;
    for(int i=0; i<H; i++){
        string s;
        cin >> s;
        if(s != string(W, '.'))
            a.push_back(s);
    }
    vector<bool> v(W, false);
    for(int i=0; i<a.size(); i++)
        for(int j=0; j<W; j++)
            if(a[i][j] == '#')
                v[j] = true;

    vector<string> ans;
    for(int i=0; i<a.size(); i++){
        string s;
        for(int j=0; j<W; j++){
            if(v[j])
                s.push_back(a[i][j]);
        }
        ans.push_back(s);
    }
    for(auto x : ans)
        cout << x << endl;

    return 0;
}
