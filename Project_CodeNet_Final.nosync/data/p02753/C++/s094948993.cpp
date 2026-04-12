#include<iostream>
using namespace std;
int main(){
    char c,p;
    cin>>p;
    for (int i = 0; i < 2; ++i) {cin>>c;if (c!=p) {cout<<"Yes"<<endl;return 0;}p=c;}
    cout<<"No"<<endl;
}
