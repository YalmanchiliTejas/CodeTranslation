#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
    int h, w; cin>>h>>w;
    string s[1010];
    for(int i=0; i<h; i++) cin>>s[i];
    int mn1=h+w, mn2=h+w, mx1=-h-w, mx2=-h-w;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j]=='B'){
                mn1=min(mn1, i+j);
                mx1=max(mx1, i+j);
                mn2=min(mn2, i-j);
                mx2=max(mx2, i-j);
            }
        }
    }
    cout<<max(mx1-mn1, mx2-mn2)<<endl;
    return 0;
}
