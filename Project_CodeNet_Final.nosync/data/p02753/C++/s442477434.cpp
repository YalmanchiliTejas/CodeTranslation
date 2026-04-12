#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
    //freopen("a.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin>>str;
    if(str[0]==str[1]&&str[1]==str[2]){
    	cout<<"No\n";
    }
    else cout<<"Yes\n";
    return 0;
}