// 模板
// #include "bits/stdc++.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <stack>
#include <cmath>
using namespace std;
#define mm(a,n) memset(a, n, sizeof(a))
#define gcd(a,b) __gcd(a,b) 
#define INF 0x3f3f3f3f  
#define EXP 1e-8  
#define lowbit(x) (x&-x)
typedef long long ll;
typedef unsigned long long ull;
 
void Main();
 
int main() {
    //应清除注释
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w", stdout);
    Main();
    // fclose(stdin);
    // fclose(stdout);
    //system("pause");  //应注释
    return 0;
}
 
void Main() {
    int num;
    cin >> num;
    if(num >= 30) cout << "Yes\n";
    else cout << "No\n";
}