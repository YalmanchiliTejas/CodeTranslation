#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;

int main(){
    int n; cin >> n;
    int Hlist[n];
    int tempmax = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> Hlist[i];
    }
    for(auto i : Hlist){
        if(i >= tempmax){
            tempmax = i;
            ans += 1;
        }
    }
    cout << ans;
    return 0; 
}