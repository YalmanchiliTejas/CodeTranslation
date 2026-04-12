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
    int n; cin>>n;
    int h[21];
    for(int i=0; i<n; i++) cin>>h[i];
    int ans=0;
    for(int i=0; i<n; i++){
        bool ok=1;
        for(int j=0; j<i; j++){
            if(h[j]>h[i]){
                ok=0;
            }
        }
        if(ok) ans++;
    }
    cout<<ans<<endl;
    return 0;
}