#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int rPay=(n/15) * 200;
    int mPay=n*800;

    cout<<mPay - rPay <<endl;


    return 0;
}