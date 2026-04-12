#include <iostream>
using namespace std;
int main(){
int n;
cin>>n;

if(n<15){
	cout<<n*800;
}
if(n>=15){
	cout<<(n*800)-(200*(n/15));
}
}