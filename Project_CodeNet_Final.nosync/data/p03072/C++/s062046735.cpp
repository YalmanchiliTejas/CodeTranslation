#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
using namespace std;


int main() {
    int n;
    cin>>n;
    int prev=0;
    int ans=0;
    for(int i=0;i<n;++i){
        int h;
        cin>>h;
        if(prev<=h)ans++;
        prev=max(prev,h);
    }
    cout<<ans<<endl;
    return 0;
}
