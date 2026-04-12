#include<iostream>
using namespace std;
int main (){
int N,x,y;
cin >> N;
x=800*N;
y=200*(N/15);
if(N/15>0){
 cout << x-y << endl;
} else {
 cout << x << endl;
}
return 0;
}