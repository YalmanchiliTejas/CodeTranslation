#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;
    
    vector<int> temp(n);
    int cand[4][2] = {{1, 1}, {1, 0}, {0, 1}, {0, 0}};
    for(int i = 0; i < 4; ++i){
        temp[0] = cand[i][0];
        temp[1] = cand[i][1];
        
        for(int j = 1; j < n-1; ++j){
            if(temp[j] == 1){
                if(s[j] == 'o'){
                    temp[j + 1] = temp[j - 1];
                }
                else{
                    temp[j + 1] = temp[j - 1] ^ 1;
                }
            }
            else{
                if(s[j] == 'x'){
                    temp[j + 1] = temp[j - 1];
                }
                else{
                    temp[j + 1] = temp[j - 1] ^ 1;
                }
            }
        }
        
        bool flag = true;
        for(int j = 0; j < n; ++j){
            if(temp[j] == 1){
                if(s[j] == 'o'){
                    if(temp[(j - 1 + n) % n] != temp[(j + 1) % n]){
                        flag = false;
                        break;
                    }
                }
                else{
                    if(temp[(j - 1 + n) % n] == temp[(j + 1) % n]){
                        flag = false;
                        break;
                    }
                }
            }
            else{
                if(s[j] == 'x'){
                    if(temp[(j - 1 + n) % n] != temp[(j + 1) % n]){
                        flag = false;
                        break;
                    }
                }
                else{
                    if(temp[(j - 1 + n) % n] == temp[(j + 1) % n]){
                        flag = false;
                        break;
                    }
                }
            }
        }
        
        if(flag){
            for(int j = 0; j < n; ++j){
                if(temp[j] == 1){
                    cout << "S";
                }
                else{
                    cout << "W";
                }
            }
            cout << "\n";
            return 0;
        }
    }
    
    cout << -1 << endl;
}