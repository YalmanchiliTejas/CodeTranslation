#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <deque>
using namespace std;
using P = pair<int,int>;
typedef long long int ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int c_cnt=0;
    int ans2 = c*max(x,y)*2;
    if(a+b>c*2){
        while(x>0 || y>0){
            c_cnt++;
            x--;
            y--;
            if(x==0 || y==0)break;
        }
    int ans = (x*a)+(y*b)+(c_cnt*c*2);
    cout << min(ans,ans2) << endl;
    return 0;
    }else{
        int ans = (x*a)+(y*b);
        cout << ans << endl;
        return 0;
    }
    return 0;
}


