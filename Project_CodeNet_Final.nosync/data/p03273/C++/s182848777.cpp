#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int H,W;
    cin >> H >> W;
    vector <string> a(H);
    for (int i = 0; i < H; i++){
        cin >> a.at(i);
    }

    int cnt = 0;
    string str(W,'.');
    for (int i = 0; i < H; i++){
        if(a[i - cnt] == str){
            a.erase(a.begin() + i - cnt);
            cnt++;
        }
    }
    
    int cnt2 = 0;
    
    for (int j = 0; j < W; j++){
        bool flag = true;
        for (int i = 0; i < H - cnt; i++){
            if (a[i][j - cnt2] != '.'){
                flag = false;
                break;
            }
        }
        if (flag){
            for (int i = 0; i < H - cnt; i++){
                a[i].erase(a[i].begin() + j - cnt2);
            }
            cnt2++;
        }
    }
    
    for (int i = 0; i < H - cnt; i++){
        cout << a.at(i) << endl;
    }
}