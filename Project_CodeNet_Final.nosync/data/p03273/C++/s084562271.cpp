#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h+10,vector<char>(w+10,'0'));
    vector<int> hflag(h+10,0),wflag(w+10,0);
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> a[i][j];
            if(a[i][j] == '#'){
                hflag[i]++;
                wflag[j]++;
            }
        }
    }
    for(int i = 1; i <= h; i++){
        if(hflag[i] == 0){
            continue;
        }
        for(int j = 1; j <= w; j++){
            if(wflag[j] == 0){
                continue;
            }
            cout << a[i][j];
        }
        cout << endl;
    }
}