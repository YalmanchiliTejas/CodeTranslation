#include <iostream>
using namespace std;

int main(){
    int i, n;
    cin>>n;
    int str[n];
    for(i=0; i<n; i++){
        cin>>str[i];
    }
    int max = 0, kosu = 0;
    for(i=0; i<n; i++){
        if(max<=str[i]){
            kosu++;
            max = str[i];
        }
    }
    cout<<kosu<<endl;

    
    return 0;
}
