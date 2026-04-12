#include <iostream>
using namespace std;
int main(void){
    int s,a,b,c;
    while(cin>>a>>b,a){
        s=a+b; c=0;
        for(int i=1; i<5; i++){
            cin>>a>>b;
            if(s<a+b)
            s=a+b,c=i;
        }
        cout<<(char)(c+'A')<<' '<<s<<endl;
    }
}

