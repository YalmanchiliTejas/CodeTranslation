#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,h;
    cin>>n;

    int high;
    cin >>high;

    int count=1;

    for (int i=0;i<n-1;i++) {
        cin >>h;
        if(h>=high){
            count++;
            high=h;
        }
    }

    cout<<count<<endl;
}
