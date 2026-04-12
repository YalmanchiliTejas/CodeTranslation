#include <iostream>
#include <string>
using namespace std;
int main(void){
    int n, k;
    string s;
    cin >> n >> s >> k;
    
    char sk = s[k-1];
    
    int i;
    for(i = 0; i<s.size(); i++){
     if(s[i] != sk) s[i] = '*';
    }
    
    cout << s << endl;
    return 0;
}
