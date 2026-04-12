#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;

int main(void){
    int r,g,b;

    cin >> r >> g >> b;

    int N = r*100+g*10+b;

    if(N%4 == 0)
        cout << "YES" << endl;

    else
        cout << "NO" << endl;
    
    return 0;
}