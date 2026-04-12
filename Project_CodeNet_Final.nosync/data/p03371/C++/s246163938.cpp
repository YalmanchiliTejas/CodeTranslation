#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int count=1e9;
    int com;
    for(int i=0;i<=2*(max(x,y));i+=2){
        com=c*i+a*(max(0,x-(i/2)))+b*(max(0,y-(i/2)));
        count=min(com,count);
    }
    cout << count << endl;
}