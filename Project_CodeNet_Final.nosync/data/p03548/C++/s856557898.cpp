#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>

#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define vsort(v) sort(v.begin(),v.end())
#define asort(a,n) sort(a, a + n)
#define vi vector<int>
#define vd vector<double>

//ここからAtCoder向けdefine
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int x, y, z;

    cin >> x >> y >> z;
    int counter = 0;
    int current = 0;
    current += z;
    while(true){
        current += y;
        current += z;
        //cout << current << endl;
        if(current > x){
            break;
        }else{
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}