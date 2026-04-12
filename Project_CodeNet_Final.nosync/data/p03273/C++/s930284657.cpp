#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    vector<string> a;
    string tmp_str;
    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> tmp_str;
        a.push_back(tmp_str);
    }
    bool erase = true;
    for(int i = 0; i < h; i++){
        erase = true;
        tmp_str = a[i].c_str();
        for(int j = 0; j < w; j++){
            if(tmp_str[j] != '.'){
                erase = false;
                break;
            }
        }
        if(erase){
            a.erase(a.begin() +i);
            h--;
            i--;
        }
    }
    for(int j = 0; j < w; j++){
        erase = true;
        for(int i = 0; i < h; i++){
            tmp_str = a[i].c_str();
            if(tmp_str[j] != '.'){
                erase = false;
                break;
            }
        }
        if(erase){
            for(int i = 0; i < h; i++){
                tmp_str = a[i].c_str();
                tmp_str.erase(j, 1);
                a[i] = tmp_str;
            }
            w--;
            j--;
        }
    }
    for(int i = 0; i < h; i++){
        cout << a[i] << endl;
    }
    return 0;
}