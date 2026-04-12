#include <iostream>
using namespace std;
int main(void){
    int n,count,maxh;
    int h[100];
    cin>>n;
    count=0;
    for (int i=0;i<n;i++) cin>>h[i];
    maxh=h[0];
    for (int i=0;i<n;i++){
        if(maxh<=h[i]){
            maxh=h[i];
            count++;
        }
    }
    cout<<count<<endl;
}
