#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int h, w;
    cin>>h>>w;
    vector<string> v(h);
    rep(i, h) cin>>v[i];
    vector<int> s1(h);
    vector<int> s2(w);
    rep(i, h){
        bool ok = true;
        rep(j, w) if(v[i][j] == '#') {
            ok = false;
            break;
        }
        if(ok) s1[i] = 1;
    }
    rep(j, w){
        bool ok = true;
        rep(i, h) if(v[i][j] == '#') {
            ok = false;
            break;
        }
        if(ok) s2[j] = 1;
    }
    rep(i, h){
        if(s1[i] == 1) continue;
        rep(j, w){
            if(s2[j] == 1) continue;
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return 0;
}