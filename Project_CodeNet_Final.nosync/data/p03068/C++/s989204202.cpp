#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

int main(void){
    int n, k;
    char s[15];
    cin >> n >> s >> k;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == s[k - 1]) cout << s[i];
        else cout << "*";
    }
    cout << endl;

}
