#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    int n;
    string s;
    int k;
    cin >> n >> s >> k;
    char t;
    t = s[k-1];
    for (int i = 0; i < n; i++){
        if(t == s[i]);
        else s[i] = '*';
    }
    cout<< s<<endl;
    return 0;
}