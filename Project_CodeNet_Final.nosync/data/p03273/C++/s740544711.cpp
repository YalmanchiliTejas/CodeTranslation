#include <iostream>
#include <string>
#include <vector>
#define FOR(i, n) for(int i = 0; i < (n); i ++)
using namespace std;
int main(void){
    int h, w;
    cin >> h >> w;
    
    vector<string> m(h);
    FOR(i, h) cin >> m[i];
    
    // h
    FOR(i, m.size()){
        bool f = true;
        FOR(j, w){
            if(m[i][j] == '#'){
                f = false;
                break;
            }
        }
        if(f){
            m.erase(m.begin() + i--);
        }
    }
    
    // w
    FOR(j, m[0].size()){
        bool f = true;
        FOR(i, m.size()){
            if(m[i][j] == '#'){
                f = false;
                break;
            }
        }
        if(f){
            FOR(i, m.size()) m[i].erase(m[i].begin() + j);
            j--;
        }
    }
    
    FOR(i, m.size()) cout << m[i] << "\n";
}
