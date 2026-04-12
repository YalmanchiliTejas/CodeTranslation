#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;
const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

int main() {
    int h,w; cin >> h >> w;
    vector<vector<char>> v(h, vector<char> (w));
    vector<int> disph(h, 0);
    vector<int> dispw(w, 0);
 
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> v[i][j];
            if(v[i][j] == '#') {disph[i]=1; dispw[j] = 1;}
        }
    }
 
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(disph[i] && dispw[j]) cout << v[i][j];
        }
        if(disph[i])cout << endl;
    }
}