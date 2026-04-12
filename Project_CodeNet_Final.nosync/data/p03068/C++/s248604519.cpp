#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n;
    string s;
    cin >> s;
    cin >> k;
    for(int i = 0; i < s.size(); i++){
        if(s[k-1] != s[i]){
            s[i] = '*';
        }
    }
    cout << s << endl;
    return 0;
}