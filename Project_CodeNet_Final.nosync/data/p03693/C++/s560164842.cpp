#include<bits/stdc++.h>
using namespace std;
 
int main(){
 int r,b,g;
 cin >> r >> b >> g;
 int num = r*100 + b*10 + g;
 if(num % 4 == 0) cout << "YES" << endl;
 else cout << "NO" << endl;
}