#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <random>

using namespace std;


int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    int total = A * X + B * Y;
    int price = 0;

    if(X > Y){
        price = C*2*Y + A*(X-Y);
        if(total > price)
            total = price;
        price = C*2*X;
        if(total > price)
            total = price;
    }else{
        price = C*2*X + B*(Y-X);
        if(total > price)
            total = price;
        price = C*2*Y;
        if(total > price)
            total = price;
    }


    cout << total << endl;
}