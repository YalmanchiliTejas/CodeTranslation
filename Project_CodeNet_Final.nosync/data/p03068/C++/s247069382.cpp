#include <iostream>
using namespace std;
//B - *e**** ********e* *e****e* ****e**
int main(void){
    int n,k;
    string s;
    
    std::cin >> n >> s >> k;
    char x=s[k-1];
    for (int i = 0; i < n; i++) {
        if(x!=s[i]){
            s[i]='*';
        }
    }
    std::cout << s << std::endl;
}
