#include <iostream>
#include <string>
using namespace std;
int main(void){
    int n;
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        sum+=800;
        if(i%15==0)sum-=200;
    }
    cout<<sum<<endl;
    return 0;
}
