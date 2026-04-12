#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    if(n <= m){
        cout << "Yes" << endl;
    }else{
        cout <<"No" << endl;
    }


    return 0;
}