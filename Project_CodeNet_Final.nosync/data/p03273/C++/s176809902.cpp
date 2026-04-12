#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w, 0));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a.at(i).at(j);
        }
    }

    vector<bool> t(h,true),y(w,true);

    for(int i = 0; i < w; i++) {
        bool p=true;
        for(int j = 0; j < h; j++) {
            if(a.at(j).at(i)=='#'){
                p=false;
            }
        }
        if(p==true){
            y[i]=false;
        }
    }

    vector<char> q(w,'.');
    for(int i = 0; i < h; i++) {
        if(a[i]==q){
            t[i]=false;
        }
    }

    for(int i = 0; i < h; i++) {
        bool l=false;
        for(int j = 0; j < w; j++) {
            if(t[i]==true && y[j]==true){
                cout << a.at(i).at(j);
                l=true;
            }
        }
        if(l==true){
            cout << endl;
        }
    }



    return 0;
}