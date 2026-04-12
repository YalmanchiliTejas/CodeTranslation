#include <bits/stdc++.h>
using namespace std;
int main(void){
    int R,G,B;
    cin >> R >> G >> B;
    int all = B+(10*G)+(100*R) ;
    if (all%4==0)
        cout <<"YES" << endl;
    else 
        cout << "NO" << endl;
    
}