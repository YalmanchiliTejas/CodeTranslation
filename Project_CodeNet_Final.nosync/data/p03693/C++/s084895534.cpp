#define DBG 0 //submit 0
#define ll long long
#if DBG
    #include <algorithm>
    #include <array>
    #include <ctime>
    #include <cstdlib>
    #include <string>
    #include <vector>
    #include <unordered_map>
    #include <iostream>
    #include <cmath>
    #include <queue>
    #include <numeric>
#else
    #include <bits/stdc++.h>
#endif

using namespace std;


int main(){
    int r,g,b;
    bool flag = false;
    cin >> r >> g >> b;
	
    if((g*10+b)%4 == 0) flag=true;
    
    cout << (flag ? "YES" : "NO") << endl;
    //cout << ans << endl;

}
