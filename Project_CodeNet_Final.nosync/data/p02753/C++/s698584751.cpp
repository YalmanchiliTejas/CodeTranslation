#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <ctime>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main(void)
{
    string s;
    cin >> s;
    if(s.at(0) == s.at(1) && s.at(1) == s.at(2)) puts("No");
    else puts("Yes");
    return 0;
}

