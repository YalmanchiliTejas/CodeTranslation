#include<iostream>
using namespace std;
int main(){
    int n,h[22],i,j,f=0,s=0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> h[i];
    }
    for(i=0;i<n;i++){
        f=0;
        for(j=0;j<i;j++){
            if(h[i]<h[j]){
                f=1;
                break;
            }
        }
        if(f==0)
            s++;
    }
    cout << s << endl;
    return 0;
}
