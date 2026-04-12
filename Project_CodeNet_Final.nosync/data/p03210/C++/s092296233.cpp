//hinagata.cpp
/*includes*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <numeric>
#include <iomanip>
#include <limits>
/*namespace*/
using namespace std;
using ll= long long;
/*define macro*/
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPi(i,a,b) for(int i=(a);i<(b);i++)
#define REPRi(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(x) (x).begin(),(x).end()

int main(){
    int X;
    cin>>X;
    if(X==7||X==5||X==3){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}