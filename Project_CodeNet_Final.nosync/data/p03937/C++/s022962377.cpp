#include <iostream>
#include <cassert>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <bitset>
#define MAXN 100000
#define ll long long
using namespace std;


string S[111];
int main() {
    int H,W;
    cin>>H>>W;
    for(int i=0;i<H;i++)
        cin>>S[i];
    
    int ct=0;
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            ct += (S[i][j]=='#');
    
    if (ct == H+W-1) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
    
}