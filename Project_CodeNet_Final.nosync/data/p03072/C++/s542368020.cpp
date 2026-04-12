#include <iostream>
using namespace std;
int main(void){
    int n,a,b,c=1;
    cin>>n>>a;
    for(int i=0;i<n-1;i++){
        cin>>b;
        if(a<=b){
            c++;
            a=b;
        }
    }
    cout<<c<<endl;
}
