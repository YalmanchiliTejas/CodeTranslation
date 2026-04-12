#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=1; i<=n; i++){
        sum+=800;
        if(i%15==0) sum-=200;
    }
    cout<<sum<<endl;
    return 0;
}