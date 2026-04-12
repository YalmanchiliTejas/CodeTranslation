#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int main(){
    map<char, int> alps;
    map<char, int> buf;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string a;
        cin >> a;
        for(char c : a){
            buf[c]++;
        }
        for(int j = 97; j < 123; j++){
            if(i==0){
                alps[(char)j] = buf[(char)j];
            } else {
                alps[(char)j] = min(alps[(char)j], buf[(char)j]);
            }
            buf[(char)j] = 0;
        }
    }
    for(int i = 97; i < 123; i++){
        while(alps[(char)i] > 0){
            cout << (char)i;
            alps[(char)i]--;
        }
    }
    cout << endl;
}
