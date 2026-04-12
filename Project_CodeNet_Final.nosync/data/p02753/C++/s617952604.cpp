/*Station and Bus*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string cad;
    
    cin >>cad;
    
    int ans = 0;
    
    for(int i = 0; i < 3; i++){
        if(cad[i]== 'A'){
            ans++;
            break;
        }
    }
    
    for(int i =0; i < 3; i++){
        if(cad[i]=='B'){
            ans++;
            break;
        }
         
    }
    
    if(ans == 2)
      cout << "Yes";
    else 
      cout << "No";
    
    return 0;
}