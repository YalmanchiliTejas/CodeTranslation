#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
main(){
    int A,B,C,n;
    cin >> A >> B >> C;
    n = A*100+B*10+C;
    if(n%4)cout << "NO" << endl;
    else cout << "YES" << endl;
}