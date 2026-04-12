#include <iostream>
using namespace std;
int main(void){
    string a;
    cin>>a;
    if(a[0]=='A'){
        if(a[1]=='A'){
            if(a[2]=='A'){
                cout<<"No";
                return 0;
            }
        }
    }else if(a[0]=='B'){
        if(a[1]=='B'){
            if(a[2]=='B'){
                cout<<"No";
                return 0;
            }
        }
    }
     cout<<"Yes";
     return 0;

    
}
