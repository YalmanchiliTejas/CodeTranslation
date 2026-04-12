#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <math.h>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
#include <cctype>
using namespace std;
int main(){
    long int A,B,AB,X,Y,p,i,a,b,answer;
    answer = 1000000010;
    cin >> A >> B >> AB >> X >> Y;
    AB *= 2;
    if(X < Y){
        p = A;
        A = B;
        B = p;
        p = X;
        X = Y;
        Y = p;
    }
    //必要数A > B
    for(i = 0;i <= X;i++){
        //iはABセットの購入数
        a = X - i;
        if(Y - i <= 0) b = 0;
        else b = Y - i;
        if(answer > a * A + b * B + i * AB){
            answer = a * A + b * B + i * AB;
        }
    }
    cout << answer << endl;
}