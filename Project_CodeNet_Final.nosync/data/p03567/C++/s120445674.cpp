#include<bits/stdc++.h>
using namespace std;

int main(void) {
    char s[6]; cin >> s;

    int flag = 0;

    for(int i = 0; s[i + 1] != '\0'; i++){
        if(s[i] == 'A' && s[i+1] == 'C'){
            flag = 1;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
   
    return 0;

}