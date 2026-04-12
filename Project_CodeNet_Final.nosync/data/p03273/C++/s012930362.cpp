#include <bits/stdc++.h>
using namespace std;

bool isSame(string s){
    if(s[0] != '.')
        return false;
    for(int i=0;i<s.size()-1;i++){
        if(s[i] != s[i+1])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    string str[h];
    vector <bool> row(h, false);
    vector <bool> col(w, false);

    for(int i=0;i<h;i++){
        cin >> str[i];
        if(isSame(str[i]))
            row[i] = true;
    }

    for(int i=0;i<w;i++){
        string s;
        for(int j=0;j<h;j++){
            s+=str[j][i];
        }
        if(isSame(s)){
            col[i] = true;
        }
    }
    for(int i=0;i<h;i++){
        string s;
        for(int j=0;j<w;j++){
            if(!row[i] && !col[j]){
                s+=str[i][j];
                cout << str[i][j];
            }
        }
        if(!row[i])
            cout << '\n';
    }
    return 0;
}
