#include <iostream>

using namespace std;

int main()
{
 string x;
    cin>>x;
    int a=0,b=0;
    for(int i=0;i<3;i++){
        if(x.at(i)=='A'){
            a++;
        }
        else{
            b++;
        }
    }
    if(a==0|| b==0){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }

    return 0;
}
