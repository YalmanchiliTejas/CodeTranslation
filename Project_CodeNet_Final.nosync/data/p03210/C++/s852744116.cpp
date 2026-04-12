#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <cstdio>
using namespace std;
typedef long long LL;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)

template <class T>
bool contain(const std::string &s, const T &v)
{
    return s.find(v) != std::string::npos;
}

int main()
{
    int x;
    cin>>x;
    if(x==3||x==5||x==7)cout << "YES" << endl;
    else cout<<"NO"<<endl;
}