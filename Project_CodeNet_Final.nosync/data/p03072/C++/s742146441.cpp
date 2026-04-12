#include<iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int num=0;
    int max=0;
    for(int i=0;i<n;i++){
        if(max<=h[i]){
            max=h[i];
            num++;
        }
    }
    cout<<num;
    return 0;
}