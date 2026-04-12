#include<bits/stdc++.h>

using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    int tmp = x / (y + z);
    int total =( x - tmp *(y + z) ) >= z ? tmp : tmp -1;
    cout << total << endl;
}
