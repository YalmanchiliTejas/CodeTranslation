#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
#define MOD (long long)1000000007
using namespace std;

int main(void){
    int n;
    cin >> n;
    int hotel,ans=0,highest=0;
    for(int i=0; i<n; i++){
        cin >> hotel;
        if(highest<=hotel)ans++;
        highest=max(hotel,highest);
    }
    cout << ans << endl;
    return 0;
}