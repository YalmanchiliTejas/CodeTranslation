#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char,int> dat[50];
map<char,int> ans;
char alp[27] = "abcdefghijklmnopqrstuvwxyz";

string str;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){ 
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            dat[i][str[j]]++;
        }
    }
  
int min = 99999;
    for(int j = 0; j < 26; j++){
        for(int i = 0; i < n; i++){
            if(min > dat[i][alp[j]]){
                min = dat[i][alp[j]];
            }
        }
        ans[alp[j]] = min;
        min = 99999;
    }

    for(auto e:ans){
        if(e.second > 0){
            for(int i = 0; i < e.second; i++){
                cout << e.first;
            }
        }
    }
    cout << endl;

    return 0;
}
