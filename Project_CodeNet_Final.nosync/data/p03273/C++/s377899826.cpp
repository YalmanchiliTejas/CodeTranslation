#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
bool a[101][101], b[101][101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h, w;
    cin >> h >> w;

    for(int i = 1; i <= h; i++){
        string line; cin >> line;
        for(int j = 0; j < w; j++){
            a[i][j+1] = (line[j] == '#' ? 1 : 0);
        }
    }
    for(int i = 1; i <= w; i++){
        bool bad = 1;
        for(int j = 1; j <= h; j++){
            if(a[j][i])bad = 0;
        }
        if(bad){
            for(int j = 1; j <= h; j++)b[j][i] = 1;
        }
    }
    for(int i = 1; i <= h; i++){
        bool row = 0; string line = "";
        for(int j = 1; j <= w; j++){
            if(a[i][j]){
                row = 1;
            }
        }
        if(!row)continue;
        for(int j = 1; j <= w; j++){
            if(b[i][j])continue;
            if(a[i][j])line += "#";
            else line += ".";
        }
        cout << line << endl;
    }
    return 0;
}
