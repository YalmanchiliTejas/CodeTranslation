#include <iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    if(N > 30)
        cout<<"Yes"<<endl;
    else if(N < 30)
        cout<<"No"<<endl;
    else if(N == 30)
        cout<<"Yes"<<endl;
    return 0;
}