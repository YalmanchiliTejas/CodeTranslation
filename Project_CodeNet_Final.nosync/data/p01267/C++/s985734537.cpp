#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
#include <set>
#include <map>
#define INF 1000000000
#define rep(i,n) for(int i =0;i<n;i++)
using namespace std;
typedef long long int ll;


int main(){
    for(;;){
        int n,a,b,c,x;
        cin >> n >> a >> b >> c >> x;
        if(!n) break;
        vector<int> Y(n);
        rep(i,n)cin >> Y[i];
        int ans = 0;
        int p=0;
        while (p<n) {
            if(x == Y[p]){
                p++;
            }
            if(ans>10000){
                ans = -1;
                break;
            }
            if(p==n)break;
            x = (a*x+b)%c;
            ans++;
        }
        cout << ans << endl;
    }
}