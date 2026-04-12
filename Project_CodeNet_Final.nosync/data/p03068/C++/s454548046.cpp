#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n,k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;
    char c = s[k-1];
    for (auto l :s){
        if (l!=c) cout << '*';
        else cout << l;
    }
    cout << endl;
    return 0;
}