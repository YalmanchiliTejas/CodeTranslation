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
}

using namespace atcoder;

int main(void){
    array<int,static_cast<int>('z')+2> c;
    c.fill(900);
    int roop;
    char m;
    cin >> roop;
    string stk;
    int ac;
    for(int i=0;i<roop;i++){
        cin >> stk;
        sort(stk.begin(),stk.end());
        int j=0;
        
        for(int search=static_cast<int>('a');search<=static_cast<int>('z');search++){
            m=static_cast<char>(search);
            ac = count(stk.begin()+j,stk.end(),m);
            c[search] = min(ac,c[search]);
            j+=ac;
        }
    }
    
    for(int i=static_cast<int>('a');i<=static_cast<int>('z');i++){
        for(int j=0;j<c[i];j++){
            
        if(c[i]==900)break;
        cout << static_cast<char>(i);
        }
    }
    cout << endl;
    return 0;
}
