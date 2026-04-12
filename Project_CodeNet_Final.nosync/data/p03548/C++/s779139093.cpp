#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    for(int i=1;;i++){
        if(a<b*i+c*(i+1)){
            cout << i-1;
            break;
        }
    }
}