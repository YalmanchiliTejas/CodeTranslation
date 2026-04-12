#include <iostream>

using namespace std;

int main(){

char A[3];
cin>> A[0]>> A[1]>> A[2];

if (A[0]==A[1] && A[1]==A[2]){ 
cout << "No" << endl;
return 0;
}
cout<<"Yes"<<endl;
return 0;
}