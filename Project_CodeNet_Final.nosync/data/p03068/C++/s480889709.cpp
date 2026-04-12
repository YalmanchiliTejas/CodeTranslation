#include <iostream>
#include <string.h>

using namespace std;

int main(void){
    int n,k;

    cin >> n;
    char s[n], ans[n];
    cin >> s;
    cin >> k;

    for(int i = 0; i < n; i++){
        if(s[i] != s[k-1]){
            strcpy(ans+i, "*");
        }
        else{
            strcpy(ans+i, s+i);
        }
    }

    cout << ans << endl;

    return 0;
}