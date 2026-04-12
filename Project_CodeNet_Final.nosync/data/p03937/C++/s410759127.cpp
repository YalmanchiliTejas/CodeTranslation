#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> math(h);
    int cnt=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char tmp;
            cin >> tmp;
            math[i].push_back(tmp);
            if(tmp=='#')cnt++;
        }
    }
    int cntw=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w-1; j++){
            if(math[i][j]=='#'&&math[i][j+1]=='#')cntw++;
        }
    }
    int cnth=0;
    for(int i=0; i<w; i++){
        for(int j=0; j<h-1; j++){
            if(math[j][i]=='#'&&math[j+1][i]=='#')cnth++;
        }
    }
    if(h-1==cnth&&w-1==cntw&&h+w-1==cnt)cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}