#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;

    char c = s[k-1];

    for(int i=0; i<n; i++){
        if(s[i] != c) s[i] = '*';
    }

    cout << s << endl;
    return 0;
}