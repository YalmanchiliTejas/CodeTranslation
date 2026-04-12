#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c;
    cin>>a;
    int e=0;
    c=0;
    int d[a];
    for(int i=0;i<a;i++){
        cin>>d[i];
        if(e<=d[i]){
            c++;
            e=d[i];
        }
    }
    cout<<c<<endl;
}
