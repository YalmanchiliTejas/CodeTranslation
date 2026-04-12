#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <stdlib.h>
#include <utility>
#include <set>
#include <map>
#include <string.h>
#include <cstring>

using namespace std;

int main(){
   
    char s[100];
    
    bool ans=false;

    cin >> s;
    for(int i=0;i<2;i++){
        if((s[i])!=s[i+1]){
            ans=true;
        }
        else continue;
    }
        
        if(ans==true) cout << "Yes" << endl;
        else cout << "No" << endl;
    return 0;
}