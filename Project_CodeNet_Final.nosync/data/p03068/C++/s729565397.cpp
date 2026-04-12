#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    string s;
    char tmp;
    int n, k;
    cin >> n >> s >> k;

    tmp = s[k - 1];
    for(int i = 0;i < n;i++){
        if(s[i] == tmp){
            ;
        }
        else{
            s[i] = '*';
        }
    }

    cout << s;

    return 0;
}