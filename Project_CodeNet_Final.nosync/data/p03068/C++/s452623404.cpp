#include<iostream>
#include<string>

int main(){
    int n,k;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    std::cin >> k;
    char c;
    c = s[k-1];
    for(int i=0; i<n; i++){
        if (s[i] != c){
            s[i] = '*';
        }
    }
    std::cout << s;
    return 0;
}