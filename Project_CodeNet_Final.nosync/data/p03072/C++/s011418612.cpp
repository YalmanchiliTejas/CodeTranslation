#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,h;
    cin>>n;
    int count=0;
    int top=0;
    for (int i=0;i<n;i++) {
        cin>>h;
        if (h>=top) {
            count++;
            top=h;
        }
    }
    cout<<count<<endl;
}
