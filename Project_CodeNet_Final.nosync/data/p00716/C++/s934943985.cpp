#include<iostream>
#include<list>
#include<cstring>
#include<algorithm>
#include <utility>
#include<stdio.h>
#include<climits>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int i,j,k,l;
    int m,y,n,f,t,max;
    double s,r;
    cin >> m;
    for(i = 0;i < m;i++){
        cin >> s;
        cin >> y;
        cin >> n;
        max = s;
        for(j = 0;j < n;j++){
            cin >> f >> r >> t;
            if(f){
                l = s;
                for(k = 0;k < y;k++){
                    l += ((int)(l*r))-t;
                }
            }
            else{
                l = 0;
                for(k = 0;k < y;k++){
                    l += ((int)((s-t*k)*r));
                }
                l += s-t*k;
            }
            if(max < l) max = l;
        }
        cout << max << endl;
    }
}