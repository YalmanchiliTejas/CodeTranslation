#include<iostream>

using namespace std;

int main(){
    
    int n,t,e,x,al;
    
    al = -1;
    cin >> n >> t >> e;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x > t+e) continue;
        if(t%x <= e || x-t%x <= e) al = i+1;
    }
    
    cout << al << endl;
    
    return(0);
}
