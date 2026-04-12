#include <bits/stdc++.h>
using namespace std;
int main(void){
    int h,w;
    char c;
    cin>>h>>w;
    int count=0;
    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            cin>>c;
            if (c=='#') {
                count++;
            }
        }
    }
    if (count==h+w-1) {
        cout<<"Possible"<<endl;
    } else {
        cout<<"Impossible"<<endl;
    }
}