#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <list>
//#include <bits/stdc++.h>


using namespace std;

#define FOR(i,a,b) for(int i=(a),i##formax=(b);i<i##formax;i++)
typedef long long ll;

int main(){
    int n, ct=0,mx=0;
    cin >> n;
    int h[n];
    FOR(i,0,n){
        cin >> h[i];
        if(h[i]>=mx){ct += 1;}
        mx = max(mx,h[i]);
    }
    cout << ct << endl;
   
    return 0;
}