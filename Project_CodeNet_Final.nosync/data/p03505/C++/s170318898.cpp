#include <iostream>
using namespace std;

int main() {
long long k,a,b,c=1;
cin>>k>>a>>b;
if(a<k){
    if(a-b<=0){
        c=-1;
    }else{
        c+=2*((k-b-1)/(a-b));
    }
}
cout<<c<<endl;
	return 0;
}
