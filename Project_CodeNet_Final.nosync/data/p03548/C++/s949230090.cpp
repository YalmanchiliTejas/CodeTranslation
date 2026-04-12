#include<bits/stdc++.h>
using namespace std;


int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int tmp=x-y-z;
    int cnt=1;
    while(1){
        if(tmp-y-2*z>=0){tmp=tmp-z-y;cnt++;}
        else break;
    }
    cout << cnt << endl;
    return 0;
}
