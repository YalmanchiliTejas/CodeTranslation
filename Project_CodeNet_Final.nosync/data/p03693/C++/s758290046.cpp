#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>
#include <typeinfo>

using namespace std;

#define FOR(i,n) for(i=0;i<n;++i)

int i,j;

int main(void){
    
    string r,g,b;
    cin >> r >> g>> b;
    string ans = r+g+b;
    auto a = atoi(ans.c_str());
    if(a%4==0)cout<<"YES";
    else cout<<"NO";
    
    
    
    
    return 0;
    
}
