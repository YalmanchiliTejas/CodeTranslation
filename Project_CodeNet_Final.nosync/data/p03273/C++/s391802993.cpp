#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> vec;
    for(int h=0; h<H; h++) {
        string str;
        cin >> str;
        
        bool flag=true;
        for(int w=0; w<W; w++) {
            if(str[w]=='#') {
                flag=false;
                break;
            }
        }
        if(!flag) {
            vec.push_back(str);
        }
    }
    
    vector<bool> ans(W, true);
    for(int w=0; w<W; w++) {
        for(int h=0; h<vec.size(); h++) {
            if(vec[h][w]=='#') {
                ans[w]=false;
                break;
            }
        }
    }
    
    for(int h=0; h<vec.size(); h++) {
        for(int w=0; w<W; w++) {
            if(!ans[w]) {
                cout << vec[h][w];
            }
        }
        cout << endl;
    }
    
    
    return 0;
    
}