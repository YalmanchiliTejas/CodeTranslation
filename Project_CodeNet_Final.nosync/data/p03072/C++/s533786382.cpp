#include<stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include<math.h>
#include <numeric>
#include<algorithm>

using namespace std;

int main(){
    int n;
    int tmp ;
    int saidai = 0;
    int ans = 0;
  cin >> n;
    for(int i = 0;i < n ;i++){
        cin >> tmp;
        if (tmp >= saidai){
            saidai = tmp;
            ans += 1 ;
        }
    }
    cout << ans << endl;
    
}
