#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <math.h>
#define rep(i,n) for (int i = 0; (i) < (n); ++ (i))
using namespace std;
 
int main(void){
    int count = 0;
    int n;
    while(1) {
        scanf("%d",&n);
        if(n == 0) break;
        if(count != 0) {
            cout << endl;
        }
        count = 1;
        
        vector<string> country(n);
        vector<int> point(n,0);
        vector<int> pointw(n,0);
        
        
        int lose,win,tie;
        rep(i,n) {
            cin >> country[i];
            scanf("%d",&win);
            scanf("%d",&lose);
            scanf("%d",&tie);
            point[i] = win*3 + tie;
            pointw[i] = win*3 + tie;
        }
        sort(point.begin(),point.end());
        int search;
        rep(i,n) {
            search = 0;
            while(pointw[search] != point[n-i-1]) search++;
            cout << country[search] << "," << point[n-i-1] << endl;
            pointw[search] = -1;
       }
    }
}
