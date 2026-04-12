#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)





int N;
//-----------------------------------------------------------------------------------
int main() {
    cin >> N;
    
    int x = 800 * N;
    int y = 200 * (N / 15);

    cout << x - y << endl;
}