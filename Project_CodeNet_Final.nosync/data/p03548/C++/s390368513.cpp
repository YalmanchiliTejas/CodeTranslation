#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int x,y,z;
    cin>>x>>y>>z;

    int i=1;
    while(1){
        if((i*y+(i+1)*z)>x){
            cout<<i-1<<endl;
            return 0;
        }
        i++;
    }

}