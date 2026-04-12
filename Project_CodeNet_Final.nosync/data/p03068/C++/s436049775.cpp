#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(auto&& i : s){
        if(i == s[k - 1]){
            cout << i;
        }else{
            cout << "*";
        }
    }
    cout << "\n";
}