#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
#define lli long long int
#define numberofdigits(x) floor(log10(x)) + 1

int main()
{
    string s;
    cin>>s;
    if(s=="AAA" || s=="BBB")
        cout<<"No\n";
    else
        cout<<"Yes\n";
    return 0;
}