#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;

int main()
{
    int n,k,i;
    string s;
    cin >> n >> s >> k;
    char temp = s.at(k-1);
    for(i = 0;i < n;++i){
        if(s.at(i) != temp){
            s.at(i) = '*';
        }
    }
    cout << s << endl;
    return 0;
}