#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main(){
    //freopen("in.txt", "r", stdin);
    int n, h;
    cin>>n;

    int cnt = 0;
    int prev = 1;
    while (n--){
        cin>>h;
        if (h>=prev) cnt++;
        prev = max(prev, h);
    }
    cout<<cnt<<endl;

    return 0;
}