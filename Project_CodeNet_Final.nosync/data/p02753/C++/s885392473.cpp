#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    char c[3];
    int a[2] = {0};
    cin >> c;
    int flag= 0;
    int tmp = c[0]-'A';
    for(int i = 1; i< 3; i++){
        if((c[i]-'A')!=tmp) flag=1;
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}