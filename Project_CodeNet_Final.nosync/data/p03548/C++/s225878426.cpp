#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main (){
    int x,y,z;
    cin >> x >> y >> z;
    for(int i=1;i<x;i++){
        if(i*(y+z)+z>x){
            cout << i-1 << endl;
            return 0;
        }
    }
    return 0;
}