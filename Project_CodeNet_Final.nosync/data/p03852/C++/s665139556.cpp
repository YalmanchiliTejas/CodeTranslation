#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <numeric>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, start, end) for(int i = start; i < end; i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main(){
    char inp;
    cin >> inp;

    bool success = false;
    char judge[] = {'a', 'i', 'u', 'e', 'o'};
    rep(i, 5) if(inp == judge[i]) success = true;

    if(success) cout << "vowel" << endl;
    else cout << "consonant" << endl;
}