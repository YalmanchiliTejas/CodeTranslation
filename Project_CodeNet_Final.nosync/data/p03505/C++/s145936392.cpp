#include <iostream>
using namespace std;
int main() {
    long long k,a,b;
    cin>>k>>a>>b;
    if(k<=a)cout<<1<<endl;
    else if(a<=b)cout<<-1<<endl;
    else if((k-a)%(a-b)==0)cout<<((k-a)/(a-b))*2+1<<endl;
    else cout<<((k-a)/(a-b))*2+3<<endl;
    
}