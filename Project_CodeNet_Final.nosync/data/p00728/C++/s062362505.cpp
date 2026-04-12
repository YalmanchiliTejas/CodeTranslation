#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /////////
    //write//
    /////////
    
    while (1){
        int n; cin >> n;
        if(n==0)break;
        int s[1000] = {0};
        for(int i=0; i<n; i++){
            cin >> s[i];
        }
        
        sort(s, s+n);
        
        int sum = 0;
        for(int i=1; i<n-1; i++){
            sum+=s[i];
        }
        sum/=(n-2);
        
        cout << sum << endl;
    }
    return 0;
}

