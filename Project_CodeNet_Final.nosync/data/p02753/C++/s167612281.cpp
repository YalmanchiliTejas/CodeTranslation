
// Problem : A - Station and Bus
// Contest : AtCoder Beginner Contest 158
// URL : https://atcoder.jp/contests/abc158/tasks/abc158_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int ans = 0;
    for(auto e : s)
    {
    	if(e == 'A') ans++;
    }
    if(ans > 0 && ans < 3) cout <<"Yes";
    else cout <<"No";
    return 0;
}