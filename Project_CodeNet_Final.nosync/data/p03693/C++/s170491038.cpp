#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    // cout << r << g << b;
    int answer = (r*100) + (g*10) + b;
    if(answer %4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
  
 
    
}
