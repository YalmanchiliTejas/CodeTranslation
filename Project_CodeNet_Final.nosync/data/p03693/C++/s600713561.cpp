#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int r,g,b,num;
    cin>>r>>g>>b;
    num=r*100+g*10+b;
    if (num%4==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    cout<<endl;
}
