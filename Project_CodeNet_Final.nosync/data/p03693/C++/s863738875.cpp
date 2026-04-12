#include <iostream>
#include <string>

using namespace std;

int r,g,b;
int X;


int main()
{
    cin>>r>>g>>b;
    
    X = 100*r+10*g+b;
    
    if(X % 4 == 0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}