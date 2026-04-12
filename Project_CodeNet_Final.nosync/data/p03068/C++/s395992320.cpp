#include <iostream>
using namespace std;
int main(void){
    int n,k;
    string s;
    cin >> n >> s >> k;
    
    for(int i=0;i<n;i++){
        if(s[i] != s[k-1]){
            s[i] = '*';
        }
    }
    
    std::cout << s << std::endl;
}
