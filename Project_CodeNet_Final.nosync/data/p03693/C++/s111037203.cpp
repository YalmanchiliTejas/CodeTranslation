#include <iostream>
#include<string>
using namespace std;
int main(void){
    // Your code here!
    string a,b,c;
    
    cin>>a>>b>>c;
    string d=a+b+c;
    int num = stoi(d);
    if(num%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
