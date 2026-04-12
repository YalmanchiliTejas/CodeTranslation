#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    vector<vector<bool>> t = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};// 0 = S, 1 = W
    for(int i=0; i<4; i++){
        for(int j=1; j<=n-2; j++){
            if(s[j] == 'o' && t[i][j] == 0) t[i].push_back(t[i][j-1]);
            if(s[j] == 'o' && t[i][j] == 1) t[i].push_back(!t[i][j-1]);
            if(s[j] == 'x' && t[i][j] == 0) t[i].push_back(!t[i][j-1]);
            if(s[j] == 'x' && t[i][j] == 1) t[i].push_back(t[i][j-1]);
        }
        bool flag1 = false, flag2 = false;
        if(s[n-1] == 'o' && t[i][n-1] == 0 && t[i][n-2] == t[i][0]) flag1 = true;
        if(s[n-1] == 'o' && t[i][n-1] == 1 && t[i][n-2] != t[i][0]) flag1 = true;
        if(s[n-1] == 'x' && t[i][n-1] == 0 && t[i][n-2] != t[i][0]) flag1 = true;
        if(s[n-1] == 'x' && t[i][n-1] == 1 && t[i][n-2] == t[i][0]) flag1 = true;

        if(s[0] == 'o' && t[i][0] == 0 && t[i][n-1] == t[i][1]) flag2 = true;
        if(s[0] == 'o' && t[i][0] == 1 && t[i][n-1] != t[i][1]) flag2 = true;
        if(s[0] == 'x' && t[i][0] == 0 && t[i][n-1] != t[i][1]) flag2 = true;
        if(s[0] == 'x' && t[i][0] == 1 && t[i][n-1] == t[i][1]) flag2 = true;

        if(flag1 == true && flag2 == true){
            for(int j=0; j<n; j++){
                if(t[i][j] == 0) cout << "S";
                if(t[i][j] == 1) cout << "W";
            }cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}