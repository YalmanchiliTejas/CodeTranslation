#include <iostream>
using namespace std;
int main(void){
    int n, h[20], c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<n;i++){
        bool f=true;
        for(int j=0;j<i;j++){
            if(h[j]>h[i])f=false;
        }
        if(f)c++;
    }
    cout<<c<<endl;
}
