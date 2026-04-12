#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    int A,B,C;
    int X,Y;
    cin >> A >> B >> C >> X >> Y;
    int cost = 0;
    if(C*2 > A+B){
        cost = X*A + Y*B;
    }
    else{
        int p = min(X,Y);
        cost += C*2*p;
        if(p == X && C*2 < B) cost += 2*C * (Y-p);
        else if(p == Y && C*2 < A) cost += 2*C * (X-p);
        else cost += (X-p)*A + (Y-p)*B;
    }
    cout << cost << endl;
    return 0;
}
