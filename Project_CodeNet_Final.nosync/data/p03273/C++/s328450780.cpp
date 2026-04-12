#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for(int tsumugi = 0; tsumugi < h; tsumugi++){
        cin >> a[tsumugi];
    }

    vector<int> row;
    for(int karen = 0; karen < h; karen++){
        bool flag = false;
        for(auto x:a[karen]){
            // cout << x << endl;
            if(x == '#'){
                flag = true;
                break;
            }
        }
        if(flag == false){
            row.insert(row.begin(), karen);
        }
    }
    for(auto x:row){
        a.erase(a.begin() + x);
    }
    h = a.size();

    vector<int> column;
    for(int karen = 0; karen < w; karen++){
        bool flag = false;
        for(int hajime = 0; hajime < h; hajime++){
            char tmp = a[hajime][karen];
            if(tmp == '#'){
                flag = true;
                break;
            }
        }
        if(flag == false){
            column.insert(column.begin(), karen);
        }
    }
    for(auto x:column){
        for(int mirai = 0; mirai < h; mirai++){
            a[mirai].erase(a[mirai].begin() + x);
        }
    }

    for(auto x:a){
        cout << x << endl;
    }
    return 0;
}