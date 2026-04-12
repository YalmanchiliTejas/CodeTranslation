#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);

    for(int i=0; i<n; ++i){
        cin >> s[i];
    }
    
    vector<int> vr, vc;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(s[i][j] == '#'){
                vr.emplace_back(i);
                break;
            }
        }
    }

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(s[j][i] == '#'){
                vc.emplace_back(i);
                break;
            }
        }
    }

    for(int i=0; i<(int)vr.size(); ++i){
        for(int j=0; j<(int)vc.size(); ++j){
            cout << s[vr[i]][vc[j]];
        }
        cout << endl;
    }
}