#include <iostream>
using namespace std;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    int k;cin>>k;

    char target = s[k-1];
    for (auto c : s){
        if (c != target){
            cout << "*";
        } else {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}