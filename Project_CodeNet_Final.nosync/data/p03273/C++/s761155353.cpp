#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for(int i = 0; i < h; i++) cin >> a[i];

    vector<bool> isliveh(h, true);
    vector<bool> islivew(w, true);
    for(int i = 0; i < h; i++){
        bool isexist = false;
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#') isexist = true;
        }
        if(!isexist) isliveh[i] = false;
    }
    for(int i = 0; i < w; i++){
        bool isexist = false;
        for(int j = 0; j < h; j++){
            if(a[j][i] == '#') isexist = true;
        }
        if(!isexist) islivew[i] = false;
    }

    vector<string> ans;
    for(int i = 0; i < h; i++){
        if(!isliveh[i]) continue;
        ans.push_back("");
        for(int j = 0; j < w; j++){
            if(!islivew[j]) continue;
            ans[ans.size()-1] += a[i][j];
        }
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    return 0;
}