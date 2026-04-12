
#include <iostream>
#include <map>

using namespace std;



int solve(){

    string str;
    
    cin >> str;
    
    unsigned long num = str.size();
    
    for(int i = 0; i < num-1; i++){
        string ac;
        ac = ac + str[i] + str[i+1];
        
        if (ac == "AC") {
            cout << "Yes" << endl;
            return 0;
        }
        
    }
    
    cout << "No" << endl;
    
    return 0;
}



int main() {
    // insert code here...
    //cout << "Hello, World!\n";
    
    solve();
    
    
    //return 0;
}
