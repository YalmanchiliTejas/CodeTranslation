#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << ((b * 10 + c) % 4 == 0 ? "YES" : "NO") << endl;
}
