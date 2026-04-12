#include <iostream>
using namespace std;
int main(){
    int a,b=0;
    cin>>a;
    for(int i=1;i<=a;i++){
        b=b+800;
        if(i%15==0)b=b-200;
    }
    cout<<b<<endl;
    return 0;
}
