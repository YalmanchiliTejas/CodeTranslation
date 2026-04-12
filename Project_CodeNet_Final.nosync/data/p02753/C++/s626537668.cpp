#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define ll long long
#define INF 0x3f3f3f3f
#define SIS std::ios::sync_with_stdio(false)
using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        if(s[0]==s[1]&&s[1]==s[2]&&s[0]==s[2])
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}
