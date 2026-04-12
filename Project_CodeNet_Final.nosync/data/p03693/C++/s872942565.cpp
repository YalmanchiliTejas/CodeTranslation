#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int a,b,c,sum;
    cin >> a >> b >> c;
    sum = (a*100) + (b*10) + c;
    if(sum % 4 > 0){
        cout << "NO" << endl;
    } 
    else cout << "YES" << endl;
}