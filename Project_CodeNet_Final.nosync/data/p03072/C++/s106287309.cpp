#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <queue>
#include <stack>
#include <stdlib.h>
using namespace std;
#define rep(i,n) for (int i = 0; i <n; i++) 
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

using namespace std;
int main(){
    int n;std::cin >> n;
    int h[n];
    rep(i,n)std::cin >> h[i];
    int ans=1;int k=h[0];
    for(int i=1;i<n;i++){
        if(h[i]==max(k,h[i]))ans++;
        k=max(h[i],k);
    }
    std::cout << ans << std::endl;
}