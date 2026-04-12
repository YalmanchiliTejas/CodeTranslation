#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int h, w, ans = 0;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++){
        cin >> s[i];
    }
    vector<bool> is_white(w);
    for(int x = 0; x < w; x++){
        bool f = true;
        for(int y = 0; y < h; y++){
            if(s[y][x] == '#') f = false;
        }
        is_white[x] = f;
    }
    for(int y = 0; y < h; y++){
        if(count(begin(s[y]), end(s[y]), '#') == 0) continue;
        for(int x = 0; x < w; x++){
            if(is_white[x]) continue;
            cout << s[y][x];
        }
        cout << endl;
    }
    return 0;
}
