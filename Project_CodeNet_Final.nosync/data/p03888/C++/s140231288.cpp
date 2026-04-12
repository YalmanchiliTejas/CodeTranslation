#include <bits/stdc++.h>

using namespace std;

int main(){
    int r_1, r_2;
    cin >> r_1 >> r_2;
    double ans = r_1*r_2*1.0/(r_1+r_2);
    printf("%.7f", ans);
    return 0;
}
