#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <queue>
#include <cmath>
#include <iterator>
#include <math.h>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_map>
#include <sstream>
#include <tuple>

using namespace std;
using lli = long long int;
using ulli = unsigned long long int;

namespace atcoder{
    void judge_outer(bool judge_exp,string ok = "Yes",string ng = "No"){
        if(judge_exp){
            cout << ok << endl;
        }else{
            cout << ng << endl;
        }
    }
    
    int ncr(int left,int right){
        right = min(left - right,right);
        int ans =1;
        for(int i=1;i<=right;i++){
            ans = ans * (left-right+i)/i;
        }
        return ans;
    }
    
    const int LIMIT = 1000000256;
    const int tenfive = 100000;
}

using namespace atcoder;

int main(void){
    int a,b,ab;
    int na,nb;
    cin >> a>> b >> ab >> na >> nb;
    ab*=2;
    int bab=ab;
    int ba = a;
    int bb = b;
    if(ab>a+b){
        bab=a+b;
    }
    if(a>ab){
        ba=ab;
    }
    if(b>ab){
        bb = ab;
    }
    int yen = 0;
    while(na>=0&&nb>=0){
        if(na>0&&nb>0){
            yen+=bab;
            na--;
            nb--;
        }else if(na>0){
            yen+=ba;
            na--;
        }else if(nb>0){
            yen+=bb;
            nb--;
        }else{
             break;
        }
    }
    cout << yen << endl;
    return 0;
}
