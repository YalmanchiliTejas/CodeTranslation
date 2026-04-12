#include <iostream>
using namespace std;

int main(){
    double R1,R2;
    cin>>R1>>R2;
    cout<<fixed;
    cout.precision(6);
    cout<<R1*R2/(R1+R2)<<endl;
}