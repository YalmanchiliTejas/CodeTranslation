#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

typedef pair<int,int> pii;

main(){
    int a, b, c;
    int num = 0;
    cin >> a >> b >> c;
    num += a*100; num+= b*10; num+=c;
    if(num%4==0) cout << "YES" << endl;
    else cout << "NO" << endl;
}