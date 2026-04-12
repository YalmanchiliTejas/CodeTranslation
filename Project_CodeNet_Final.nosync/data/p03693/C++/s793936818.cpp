#include<string>
#include<iostream>

using namespace std;




int main() {
//    MaximumRange m;
//    cout<<m.findMax("+--+--+")<<endl;
    int r,g,b;
    cin>>r>>g>>b;
    int a=r*100+g*10+b;
    if(a%4==0){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }
}
