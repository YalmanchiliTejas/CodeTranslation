#include <iostream>
using namespace std;
int main(void){
    // Here your code !
    char r,b,g;
    cin>>r>>b>>g;
    int result = (int)(r -'0')*100+(int)(b -'0')*10+(int)(g -'0');
    string str =(result%4 == 0)?"YES":"NO";
    cout<<str<<endl;
}