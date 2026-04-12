#include<bits/stdc++.h>
using namespace std;
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int a, b, c;
cin >> a >> b >> c;
((b*10 + c)%4 == 0) ? cout << "YES\n" : cout << "NO\n";
return 0;
}
