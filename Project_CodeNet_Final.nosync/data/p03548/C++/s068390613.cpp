#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    long X, Y, Z;
    int cnt = 0;
    cin >> X >> Y >> Z;
    if(X == Y + 2 * Z){
        cout << "1" << endl;
    }else{
        long Dis = X - 2*Z - Y;
        while(Dis > 0){
            Dis = Dis - (Y + Z);
            if(Dis >= 0) cnt++;
            if(Dis < 0) break;
        }
        cout << cnt + 1 << endl;
    }
    
        return 0;
}