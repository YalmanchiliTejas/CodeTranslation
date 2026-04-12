#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;

    char save = s[k-1];
    for(int i = 0; i < n; i++){
        if(s[i] == save){
            cout << save;
        }else{
            cout << "*";
        }
        
    }
    cout << endl;
    
    return 0;
}
