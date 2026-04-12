#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int h, w, ans = 0;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++){
        cin >> s[i];
    }
    vector<bool> row(h), col(w);
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            if(s[y][x] == '#') row[y] = col[x] = true;
        }
    }
    for(int y = 0; y < h; y++){
        if(!row[y]) continue;
        for(int x = 0; x < w; x++){
            if(!col[x]) continue;
            cout << s[y][x];
        }
        cout << endl;
    }
    return 0;
}
