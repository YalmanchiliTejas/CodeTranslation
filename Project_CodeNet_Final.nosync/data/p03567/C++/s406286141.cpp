#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
    if (s[i - 1] == 'A' && s[i] == 'C'){
        cout << "Yes";
        return 0;
    }
    cout << "No";

}
