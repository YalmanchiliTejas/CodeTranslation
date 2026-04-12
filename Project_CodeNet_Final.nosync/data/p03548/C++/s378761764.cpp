#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int i=0;
    int ky=0;
    while(1){
        if(i==0)ky+=z;
        ky+=(y+z);
        i++;
        if(ky>x){
            cout << i-1 << endl;
            return 0;
        }
        if(ky==x){
            cout << i << endl;
            return 0;
        }
    }
}