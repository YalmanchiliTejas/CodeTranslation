#include<bits/stdc++.h>
using namespace std;
int n, m, a[1000][1000];

int main(){
    cin >> n >> m;
    string ss = "";
    for (int i = 1; i <= m; i++) ss += '.';
    string s;
    vector<string> v;
    for (int i = 1; i <= n; i++){
        cin >> s;
        if (s != ss) v.push_back(s);
    }
    //for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
    for (int i = 0; i < m; i++){
        bool dd = true;
        for (int j = 0; j < v.size(); j++){
            if (v[j][i] == '#') dd = false;
        }
        if (dd){
            for (int j = 0; j < v.size(); j++) v[j][i] = ' ';
        }
    }
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < m; j++){
            if (v[i][j] != ' ') cout << v[i][j];
        }
        cout << endl;
    }    
    
}