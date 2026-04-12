#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int ans = 0;
    int m = 0;
    
   for(int i = 0; i < n; i++){
       if(i == 0){
           m = v[0];
           ans++;
       }
       else{
           if(v[i] >= m){
               m = v[i];
               ans++;
           }
       }
    }
    cout << ans << "\n";
}
