#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> map(h);
    for(int i = 0; i < h; i++){
        cin >> map[i];
    }
    string chk(w,'.');
    vector<int> check1(h,0);
    for(auto itr = map.begin(); itr != map.end(); itr++){
        if(chk == *itr){
            check1[itr-map.begin()] = 1;
        }
    }
    vector<int> check(w,0);
    for(int i = 0; i < w; i++){
        int j = 0;
        while(j < h&&map[j][i] == '.')
            j++;
        if(j == h){
            check[i] = 1;
        }
    }
    for(int i = 0; i < h; i++){
        if(check1[i] == 1)
            continue;
        for(int j = 0; j < w; j++){
            if(check[j] == 1){
                continue;
            }
            else
                cout << map[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
