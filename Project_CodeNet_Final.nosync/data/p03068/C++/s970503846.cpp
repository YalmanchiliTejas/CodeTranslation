#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n >> s >> k;
    char target = s[k-1];
    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[i] == target)continue;
        else s[i] = '*';
    }
    cout << s << endl;
     
    return 0;
}