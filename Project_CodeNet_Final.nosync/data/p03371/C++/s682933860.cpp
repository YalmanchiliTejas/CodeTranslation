#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int big = ((x >= y)? x : y), small = ((x >= y)? y : x);
    int min = 1000000000;
    for(int i = 0; i <= big; i++){
        int tmp;
        if(i <= small){
            tmp = c * i * 2 + (a * (x - i)) + (b * (y - i));
        }
        else{
            if(small == x){
                tmp = c * i * 2 + b * (y - i);
            }
            else{
                tmp = c * i * 2 + a * (x - i);
            }
        }
        if(tmp < min){
            min = tmp;
        }
    }

    cout << min << endl;

    return 0;
}