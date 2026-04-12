#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cmath>
#include <map>
#define ull unsigned long long
#define ll long long
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int cmp1=c*2*max(x,y);
    int cmp2;
    int cmp3=a*x+b*y;
    if(x>y){
        cmp2=c*2*min(x,y)+a*abs(x-y);
    }
    else{
        cmp2=c*2*min(x,y)+b*abs(x-y);
    }
    cout << min(min(cmp1,cmp2),min(cmp2,cmp3)) << endl;


    return 0;
}