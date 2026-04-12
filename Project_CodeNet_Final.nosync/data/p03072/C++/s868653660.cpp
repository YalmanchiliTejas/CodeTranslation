#include <iostream>
using namespace std;

int main(){
  
    int n, i, h[25];
    cin >> n;
    
    for( i=0; i<n; i++){
    cin >> h[i];
    }

    int count=0, max=h[0];
  
    for(i=1; i<n; i++){
    if(h[i] >= max){
    count++;
    max=h[i];
    }
    }

    cout << count+1 <<endl;

}

    