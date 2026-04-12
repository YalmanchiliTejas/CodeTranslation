#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    string s;
    cin >> s;
    int n = s.size();
    int num = 0;
    for(int i=0;i < n-1;i++){
        if(s[i]=='A' && s[i+1] == 'C'){
            num++;
        }
    }
    if(num >= 1){
        cout <<"Yes" << endl;
    }
    else{
        cout <<"No" << endl;
    }
}
