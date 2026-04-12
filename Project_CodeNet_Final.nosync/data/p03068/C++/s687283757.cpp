#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>

typedef long long ll;
using namespace std;

int main()
{
    int n, k;
    string s;
    char a;
    cin >> n >> s >> k;
    a = s[k-1];
    for (int i = 0; i<s.size(); i++) {
        if(s[i] != a) s[i] = '*'; 
    }
    cout << s << endl;

    return 0;
}
