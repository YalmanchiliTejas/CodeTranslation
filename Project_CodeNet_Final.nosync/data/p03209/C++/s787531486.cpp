#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

long long h(long long n){
    if(n == 0) return 1;
    else return h(n-1) * 2 + 3;
}

long long pt(long long n){
    if(n == 0) return 1;
    else return pt(n-1) * 2 + 1;
}

long long slove(long long n, long long k){
    long long ht = h(n);
    long long htdiv = ht / 2 + 1;
    long long rpt;
    // cout << endl;
    // cout << n << " " << k << endl;
    // cout << ht << " " << htdiv << endl;
    
    if(k == ht){
        // cout << "k == ht" << endl;
        rpt = pt(n);
    }else if(n == 1){
        // cout << "n is 1" << endl;
        if (2 <= k && k <= 4) rpt = k - 1;
        else rpt = 0;
    }else if(k > htdiv){
        // cout << "k > htdiv" << endl;
        rpt = slove(n-1, k-htdiv) + pt(n - 1) + 1;
    }else if(k == htdiv){
        // cout << "k == htdiv" << endl;
        rpt = pt(n - 1) + 1;
    }else{
        // cout << "k < htdiv" << endl;
        rpt = slove(n-1, k-1);
    }
    // cout << "rpt is " << rpt << endl;
    return rpt;
}

int main(void){
    long long n, k;
    cin >> n >> k;
    cout << slove(n, k) << endl;
    return 0;
}